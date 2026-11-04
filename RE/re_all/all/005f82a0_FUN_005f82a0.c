
undefined4 FUN_005f82a0(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  longlong lVar2;
  undefined1 local_10 [16];
  
  *param_2 = 0;
  *param_3 = 0;
  lVar2 = FUN_005f7ef0(param_1,local_10,0x10000,0);
  iVar1 = (int)lVar2;
  while( true ) {
    if ((iVar1 == -2) && ((int)((ulonglong)lVar2 >> 0x20) == -1)) {
      return 0;
    }
    if (lVar2 < 0) {
      return (int)lVar2;
    }
    iVar1 = FUN_006a8260(local_10);
    if (iVar1 == 0) break;
    iVar1 = FUN_005f83d0(local_10,*param_2,*param_3);
    if (iVar1 != 0) {
      if ((void *)*param_2 != (void *)0x0) {
        _free((void *)*param_2);
      }
      *param_2 = 0;
      *param_3 = 0;
      return 0xffffff7b;
    }
    FUN_005f8370(local_10,param_2,param_3);
    lVar2 = FUN_005f7ef0(param_1,local_10,0x10000,0);
    iVar1 = (int)lVar2;
  }
  return 0;
}

