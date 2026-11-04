
undefined4 FUN_00466b20(void)

{
  uint *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 extraout_var;
  undefined4 uVar6;
  
  puVar1 = (uint *)FUN_004ce990(1);
  uVar6 = extraout_var;
  if ((uint)((int)(*puVar1 & 0xf00) >> 8) < 2) {
    puVar2 = (undefined4 *)FUN_004ce990(2);
    uVar3 = FUN_00487080(*puVar2);
    puVar1 = (uint *)FUN_004ce990(1);
    iVar4 = (int)(*puVar1 & 0xf00) >> 8;
    puVar1 = (uint *)FUN_004ce990(1);
    iVar5 = (int)(*puVar1 & 0xf0) >> 4;
    puVar1 = (uint *)FUN_004ce990(1);
    FUN_0044afb0(*puVar1 & 0xf,iVar5,iVar4,uVar3);
  }
  puVar1 = (uint *)FUN_004ce990(1);
  if ((int)(*puVar1 & 0xf00) >> 8 == 2) {
    FUN_004b8b50(uVar6);
  }
  return 1;
}

