
int FUN_006b8b90(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 local_40 [64];
  
  puVar1 = *(undefined4 **)(param_1 + 0x3c);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = _calloc(1,0x10);
    *(undefined4 **)(param_1 + 0x3c) = puVar1;
    if (puVar1 == (undefined4 *)0x0) {
      return -1;
    }
    *puVar1 = FUN_006b8b50;
  }
  FUN_006b88f0(local_40,param_1);
  iVar2 = FUN_006bdf70(local_40,param_2,puVar1 + 1,param_3);
  if (-1 < iVar2) {
    FUN_006b8c10(param_1,local_40);
    iVar2 = 0;
  }
  return iVar2;
}

