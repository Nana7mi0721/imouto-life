
undefined4 __fastcall FUN_00458470(int param_1)

{
  uint *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  *(undefined4 *)(param_1 + 0x884) = 0;
  puVar1 = (uint *)FUN_004ce990(2);
  if (((*puVar1 & 0x1000) != 0) && (iVar2 = FUN_004ce080(), 3 < iVar2)) {
    puVar3 = (undefined4 *)FUN_004ce990(3);
    uVar4 = FUN_00487080(*puVar3);
    *(undefined4 *)(param_1 + 0x884) = uVar4;
  }
  *(undefined4 *)(param_1 + 0x24) = 0;
  puVar1 = (uint *)FUN_004ce990(2);
  if ((*puVar1 & 0x80) == 0) {
    FUN_0044f9f0();
  }
  else {
    *(undefined1 *)(param_1 + 0xe) = 1;
    puVar1 = (uint *)FUN_004ce990(2);
    iVar2 = (int)(*puVar1 & 0xf00) >> 8;
    if (iVar2 == 1) {
      FUN_00429cb0(1,0,param_1 + 0x854,0xffffffff);
    }
    else if (iVar2 == 2) {
      FUN_00429e40(1,0,param_1 + 0x858,0xffffffff);
    }
  }
  return 1;
}

