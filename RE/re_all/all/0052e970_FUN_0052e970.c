
undefined4 FUN_0052e970(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = FUN_0052df70();
    return uVar1;
  }
  puVar3 = &DAT_00a496fc;
  for (iVar2 = 0xd; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *param_1;
    param_1 = param_1 + 1;
    puVar3 = puVar3 + 1;
  }
  PTR_FUN_0084c9d0 = &LAB_0052d1b0;
  PTR_FUN_0084c9d4 = &DAT_0052d230;
  PTR_FUN_0084c9d8 = &DAT_0052d240;
  PTR_FUN_0084c9dc = &LAB_0052d250;
  PTR_FUN_0084c9e0 = &DAT_0052d270;
  PTR_DAT_0084c9e4 = &DAT_0052d280;
  PTR_LAB_0084c9e8 = &DAT_0052d290;
  DAT_0084c9ec = &LAB_0052d2a0;
  PTR_FUN_0084c9f0 = &LAB_0052d310;
  PTR_FUN_0084c9f4 = &LAB_0052d3a0;
  DAT_0084c9f8 = &LAB_0052d430;
  PTR_DAT_0084c9fc = &LAB_0052d4c0;
  PTR_FUN_0084ca00 = &DAT_0052d500;
  return 0;
}

