
undefined4 FUN_005956e0(HANDLE param_1,LONG param_2,undefined4 param_3,int param_4)

{
  if (param_4 != 0) {
    if (param_4 == 1) {
      SetFilePointer(param_1,param_2,(PLONG)0x0,1);
      return 0;
    }
    if (param_4 == 2) {
      SetFilePointer(param_1,param_2,(PLONG)0x0,2);
      return 0;
    }
  }
  SetFilePointer(param_1,param_2,(PLONG)0x0,0);
  return 0;
}

