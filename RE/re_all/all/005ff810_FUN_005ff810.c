
undefined4 __thiscall
FUN_005ff810(int param_1,int param_2,undefined4 *param_3,uint param_4,int param_5,undefined4 param_6
            ,undefined4 param_7)

{
  undefined4 uVar1;
  undefined8 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b23b8;
  local_c = ExceptionList;
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    ExceptionList = &local_c;
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x7c));
    local_4 = 0;
    if (*(int *)(param_1 + 0x18) == 0) {
      *param_3 = 0;
    }
    else if (param_2 < 2) {
      *param_3 = 0;
    }
    else {
      uVar2 = FUN_005ff8e0(param_6,param_7,param_6,param_7,param_2,param_2 >> 0x1f,0,0);
      uVar1 = __alldiv(param_4 - (uint)uVar2,
                       (param_5 - (int)((ulonglong)uVar2 >> 0x20)) - (uint)(param_4 < (uint)uVar2),
                       param_2 + -1,param_2 + -1 >> 0x1f);
      uVar1 = FUN_005ffc70(uVar1);
      *param_3 = uVar1;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x7c));
    uVar1 = 0;
  }
  ExceptionList = local_c;
  return uVar1;
}

