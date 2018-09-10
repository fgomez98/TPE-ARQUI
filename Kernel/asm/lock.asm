GLOBAL getLock
GLOBAL releaseLock
section .text

getLock:
  lock bts [lock], 0 ;try to get the lock
  jc .spin_with_pause ;spin if it is locked
  ret

.spin_with_pause:
  pause
  test dword [lock], 1 ;is it free?
  jc .spin_with_pause
  jmp getLock

releaseLock:
  lock btr [lock],0
  ret
