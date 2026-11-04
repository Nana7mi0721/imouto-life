
undefined * __thiscall FUN_00452590(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined *local_10;
  
  iVar1 = FUN_00487080(param_2);
  if (iVar1 < -2) {
    puVar2 = (undefined *)FUN_004d2620(-3 - iVar1);
    return puVar2;
  }
  if (iVar1 == -2) {
    return &DAT_00a14438;
  }
  if (iVar1 != -1) {
    iVar1 = FUN_0046f600(iVar1);
    if ((iVar1 == -1) || (iVar6 = FUN_004d29a0(), iVar6 <= iVar1)) {
      local_10 = (undefined *)0x0;
    }
    else {
      local_10 = (undefined *)FUN_004d2a00(iVar1);
    }
    return local_10;
  }
  if (*(int *)(param_1 + 0x14) != -1) {
    uVar3 = FUN_004d29a0();
    uVar4 = FUN_0046f600(*(undefined4 *)(param_1 + 0x14));
    if (uVar4 < uVar3) {
      uVar5 = FUN_0046f600(*(undefined4 *)(param_1 + 0x14));
      puVar2 = (undefined *)FUN_004d2a00(uVar5);
      return puVar2;
    }
  }
  return (undefined *)0x0;
}

