
undefined4 FUN_0045ca90(void)

{
  uint *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 extraout_var;
  
  puVar1 = (uint *)FUN_004ce990(1);
  if ((*puVar1 & 0x1000000) == 0) {
    uVar2 = FUN_004ce080(extraout_var);
    if (uVar2 < 4) {
      puVar3 = (undefined4 *)FUN_004ce990(2);
      uVar4 = FUN_00487080(*puVar3);
      puVar1 = (uint *)FUN_004ce990(1);
      iVar5 = ((((int)(*puVar1 & 0xff0000) >> 0x10) + -100) * 0xff) / 100;
      puVar1 = (uint *)FUN_004ce990(1);
      iVar6 = ((((int)(*puVar1 & 0xff00) >> 8) + -100) * 0xff) / 100;
      puVar1 = (uint *)FUN_004ce990(1);
      FUN_004a57d0((int)(((*puVar1 & 0xff) - 100) * 0xff) / 100,iVar6,iVar5,uVar4);
    }
    else {
      puVar3 = (undefined4 *)FUN_004ce990(2);
      uVar4 = FUN_00487080(*puVar3);
      puVar3 = (undefined4 *)FUN_004ce990(5);
      iVar5 = FUN_00487080(*puVar3);
      iVar5 = ((iVar5 + -100) * 0xff) / 100;
      puVar3 = (undefined4 *)FUN_004ce990(4);
      iVar6 = FUN_00487080(*puVar3);
      iVar6 = ((iVar6 + -100) * 0xff) / 100;
      puVar3 = (undefined4 *)FUN_004ce990(3);
      iVar7 = FUN_00487080(*puVar3);
      FUN_004a57d0(((iVar7 + -100) * 0xff) / 100,iVar6,iVar5,uVar4);
    }
  }
  else {
    uVar2 = FUN_004ce080(extraout_var);
    if (uVar2 < 4) {
      puVar3 = (undefined4 *)FUN_004ce990(2);
      uVar4 = FUN_00487080(*puVar3);
      puVar1 = (uint *)FUN_004ce990(1);
      iVar5 = ((((int)(*puVar1 & 0xff0000) >> 0x10) + -100) * 0xff) / 100;
      puVar1 = (uint *)FUN_004ce990(1);
      iVar6 = ((((int)(*puVar1 & 0xff00) >> 8) + -100) * 0xff) / 100;
      puVar1 = (uint *)FUN_004ce990(1);
      FUN_004a5870((int)(((*puVar1 & 0xff) - 100) * 0xff) / 100,iVar6,iVar5,uVar4);
    }
    else {
      puVar3 = (undefined4 *)FUN_004ce990(2);
      uVar4 = FUN_00487080(*puVar3);
      puVar3 = (undefined4 *)FUN_004ce990(5);
      iVar5 = FUN_00487080(*puVar3);
      iVar5 = ((iVar5 + -100) * 0xff) / 100;
      puVar3 = (undefined4 *)FUN_004ce990(4);
      iVar6 = FUN_00487080(*puVar3);
      iVar6 = ((iVar6 + -100) * 0xff) / 100;
      puVar3 = (undefined4 *)FUN_004ce990(3);
      iVar7 = FUN_00487080(*puVar3);
      FUN_004a5870(((iVar7 + -100) * 0xff) / 100,iVar6,iVar5,uVar4);
    }
  }
  return 1;
}

