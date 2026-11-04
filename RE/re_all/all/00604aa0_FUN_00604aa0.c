
int __thiscall FUN_00604aa0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_005ffec0(param_2,param_3,(LPCRITICAL_SECTION)(param_1 + 0x5c),param_4);
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x5c));
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x74));
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0x90) = 0;
  return param_1;
}

