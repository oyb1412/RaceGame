
#ifndef SYSTEM_TIMER_H_
#define SYSTEM_TIMER_H_


class tag_System_Timer
{
private:
	bool g_bTimerStopped = true; 
	LONGLONG g_TicksPerSec = 0;  
	LONGLONG g_StopTime;         
	LONGLONG g_LastElapsedTime;  
	LONGLONG g_BaseTime;         

public:

	virtual void Init(void);

	void Reset(void);

	void Start(void);

	void Stop(void);

	void Advance(void);

	double GetTime(void);

	double GetAbsoluteTime(void);

	float GetElapsedTime(void);

	bool IsStoped(void);

	void LimitThreadAffinityToCurrentProc(void);

	LARGE_INTEGER GetAdjustedCurrentTime(void);

};
extern tag_System_Timer System_Timer;
#endif // SYSTEM_TIMER_H_
