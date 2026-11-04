
undefined4 FUN_0045cdd0(void)

{
  undefined4 *puVar1;
  uint *puVar2;
  
  puVar1 = (undefined4 *)FUN_004ce990(1);
  DAT_00a18af4 = *puVar1;
  puVar2 = (uint *)FUN_004ce990(2);
  DAT_00a18af8 = *puVar2 & 0xffff;
  puVar2 = (uint *)FUN_004ce990(2);
  DAT_00a18afc = (*puVar2 & 0x10000) != 0;
  FUN_00476220(DAT_00a18af4,DAT_00a18af8,DAT_00a18afc);
  return 1;
}

