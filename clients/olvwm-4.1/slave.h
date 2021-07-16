#if !defined(SLAVE_H)
#define SLAVE_H

pid_t SlaveStart(char **argv);
void SlaveStop(void);
void SlaveStopped(void);
static void SlaveFailure(void);

#endif

