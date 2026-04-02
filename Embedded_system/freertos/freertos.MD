freertos

typedef struct {
  const char       *name;       ///< 线程名称
  uint32_t         attr_bits;   ///< 属性位
  void            *cb_mem;      ///< 线程控制块内存
  uint32_t         cb_size;     ///< 提供的控制块内存大小
  void           *stack_mem;    ///< 栈内存
  uint32_t        stack_size;   ///< 栈大小
  osPriority_t     priority;    ///< 初始线程优先级（默认：普通优先级）
  TZ_ModuleId_t    tz_module;   ///< 可信区模块编号
  uint32_t         reserved;    ///< 保留（必须为 0）
} osThreadAttr_t;

osThreadId_t osThreadNew(
    osThreadFunc_t func,       // 线程函数
    void *argument,            // 传入参数
    const osThreadAttr_t *attr // 线程属性（优先级、栈大小、名称等）
);


osThreadTerminate(osThreadId thread_id); //终止任务


/***绝对延时函数。常⽤于较精确的周期运⾏任务，⽐如我有⼀个任务，希望它以固定频率定期执⾏，⽽不受外部的影响，任务从上⼀次运⾏开始到下⼀次运⾏开始的时间间隔是绝对的，⽽不是相对的。***/

osStatus osDelayUntil (uint32_t *PreviousWakeTime, uint32_t millisec);
//参数:PreviousWakeTime： 任务上⼀次离开阻塞态(被唤醒)的时刻。这个时刻被⽤作⼀个参考点来计算该任务下⼀次离开阻塞态的
//时刻:millisec： 毫秒数

osStatus osThreadSuspend (osThreadId thread_id);
osStatys osThreadSuspendAll(void);
//Suspend ： 挂起， 暂停
//挂起指定任务。被挂起的任务绝不会得到 CPU 的使⽤权，不管该任务具有什么优先级。

BaseType_t osThreadResume( TaskHandle_t xTaskToResume );
BaseType_t osThreadResumeAll(void);
Resume ： 恢复，继续
让挂起的任务重新进⼊就绪状态，恢复的任务会保留挂起前的状态信息，在恢复的时候根据挂起时的状态继续运⾏。如果被恢复任务在所
有就绪态任务中，处于最⾼优先级列表的第⼀位，那么系统将进⾏任务上下⽂的切换。可⽤在中断服务程序中。

osThreadState osThreadGetState(osThreadId thread_id);
获取任务当前状态。
