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





