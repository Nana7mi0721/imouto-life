
void FUN_0056d970(int param_1,undefined4 param_2)

{
  switch(param_2) {
  case 0:
    SetThreadPriority(*(HANDLE *)(param_1 + 8),-2);
    return;
  case 1:
    SetThreadPriority(*(HANDLE *)(param_1 + 8),-1);
    return;
  case 2:
    SetThreadPriority(*(HANDLE *)(param_1 + 8),0);
    return;
  case 3:
    SetThreadPriority(*(HANDLE *)(param_1 + 8),2);
  }
  return;
}

