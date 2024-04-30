
#include <Windows.h>
#include "system_timer.h"




void tag_System_Timer::Init(void)
{
    g_bTimerStopped = true;
    g_TicksPerSec = 0;
    g_StopTime = 0;
    g_LastElapsedTime = 0;
    g_BaseTime = 0;

    LARGE_INTEGER ticksPerSec = { 0 };
    QueryPerformanceFrequency(&ticksPerSec);
    g_TicksPerSec = ticksPerSec.QuadPart;
}

void tag_System_Timer::Reset(void)
{
    LARGE_INTEGER time = GetAdjustedCurrentTime();

    g_BaseTime = g_LastElapsedTime = time.QuadPart;
    g_StopTime = 0;
    g_bTimerStopped = false;
}

void tag_System_Timer::Start(void)
{
    LARGE_INTEGER time = { 0 };
    QueryPerformanceCounter(&time);

    if( g_bTimerStopped ) {
        g_BaseTime += time.QuadPart - g_StopTime;
    }

    g_StopTime = 0;
    g_LastElapsedTime = time.QuadPart;
    g_bTimerStopped = false;
}

void tag_System_Timer::Stop(void)
{
    if( g_bTimerStopped ) return;

    LARGE_INTEGER time = { 0 };
    QueryPerformanceCounter(&time);

    g_LastElapsedTime = g_StopTime = time.QuadPart; 
    g_bTimerStopped = true;
}

void tag_System_Timer::Advance(void)
{
    g_StopTime += g_TicksPerSec / 10;
}

double tag_System_Timer::GetTime(void)
{
    LARGE_INTEGER time = GetAdjustedCurrentTime();

    return (double)(time.QuadPart - g_BaseTime) / (double)g_TicksPerSec;
}

double tag_System_Timer::GetAbsoluteTime(void)
{
    LARGE_INTEGER time = { 0 };
    QueryPerformanceCounter(&time);

    return time.QuadPart / (double)g_TicksPerSec;
}

float tag_System_Timer::GetElapsedTime(void)
{
    LARGE_INTEGER time = GetAdjustedCurrentTime();

    double elapsed_time = (float)((double)(time.QuadPart - g_LastElapsedTime) / (double)g_TicksPerSec);
    g_LastElapsedTime = time.QuadPart;

    
    
    if( elapsed_time < 0.0f ) {
        elapsed_time = 0.0f;
    }

    return (float)elapsed_time;
}

bool tag_System_Timer::IsStoped(void)
{
    return g_bTimerStopped;
}

void tag_System_Timer::LimitThreadAffinityToCurrentProc(void)
{
    HANDLE hCurrentProcess = GetCurrentProcess();

    // Get the processor affinity mask for this process
    DWORD_PTR dwProcessAffinityMask = 0;
    DWORD_PTR dwSystemAffinityMask = 0;

    if( GetProcessAffinityMask(hCurrentProcess, &dwProcessAffinityMask, &dwSystemAffinityMask) != 0 && dwProcessAffinityMask ) {
        // Find the lowest processor that our process is allows to run against
        DWORD_PTR dwAffinityMask = (dwProcessAffinityMask & ((~dwProcessAffinityMask) + 1));

        // Set this as the processor that our thread must always run against
        // This must be a subset of the process affinity mask
        HANDLE hCurrentThread = GetCurrentThread();
        if( INVALID_HANDLE_VALUE != hCurrentThread ) {
            SetThreadAffinityMask(hCurrentThread, dwAffinityMask);
            CloseHandle(hCurrentThread);
        }
    }

    CloseHandle(hCurrentProcess);
}

LARGE_INTEGER tag_System_Timer::GetAdjustedCurrentTime(void)
{
    LARGE_INTEGER time;
    if( g_StopTime != 0 ) {
        time.QuadPart = g_StopTime;
    }
    else {
        QueryPerformanceCounter(&time);
    }

    return time;
}
