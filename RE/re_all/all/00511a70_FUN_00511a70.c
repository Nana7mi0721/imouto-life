
undefined4 FUN_00511a70(short param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c;
  
  if (DAT_00a24d60 == 0) {
    return 0xffffffff;
  }
  iVar1 = 0;
  puVar2 = &DAT_00a24e84;
  if (0 < DAT_00a2d284) {
    do {
      if (param_1 == *(short *)((int)puVar2 + 6)) break;
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 0x42;
    } while (iVar1 < DAT_00a2d284);
  }
  if (((iVar1 == DAT_00a2d284) || (puVar2 == (undefined4 *)0x0)) ||
     (iVar1 = FUN_0050f020(), iVar1 != 0)) {
    return 0xffffffff;
  }
  if (DAT_00aba24c == 0) {
    FUN_0057a980();
  }
  iVar1 = DAT_00aba24c;
  if (DAT_00aba250 == 0) {
    FUN_0057a980();
  }
  FUN_005764b0(local_c,0xffffffff,DAT_00aba250,param_2,0x7fffffff,iVar1);
  return 0;
}

