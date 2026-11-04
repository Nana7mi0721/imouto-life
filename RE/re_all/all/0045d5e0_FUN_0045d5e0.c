
undefined4 FUN_0045d5e0(void)

{
  undefined4 *puVar1;
  undefined3 uVar4;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_2c [16];
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  int local_10;
  undefined1 *local_c;
  int local_8;
  
  uStack_18 = 1;
  uStack_1c = 0x45d5f9;
  puVar1 = (undefined4 *)FUN_004ce990();
  uStack_18 = *puVar1;
  uStack_1c = 0x45d604;
  local_8 = FUN_00452590();
  if (local_8 == 0) {
    uVar4 = 0;
  }
  else {
    uStack_18 = 0;
    uStack_1c = 0x45d624;
    iVar2 = FUN_004ce810();
    if ((*(byte *)(iVar2 + 5) & 4) != 0) {
      uStack_18 = 1;
      uStack_1c = 0x45d63d;
      puVar1 = (undefined4 *)FUN_004ce990();
      *(undefined4 *)(local_10 + 0x894) = *puVar1;
    }
    uStack_18 = 0;
    uStack_1c = 0x45d65b;
    uVar3 = FUN_004ce810();
    local_c = auStack_2c;
    local_14 = FUN_004a5960(uVar3);
    uVar3 = FUN_004a59d0();
    if (DAT_00a18c7c != 0) {
      uStack_18 = 0x45d685;
      uVar3 = FUN_0044cf90();
    }
    uVar4 = (undefined3)((uint)uVar3 >> 8);
  }
  return CONCAT31(uVar4,1);
}

