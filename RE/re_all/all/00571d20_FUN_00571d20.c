
undefined4 FUN_00571d20(uint param_1)

{
  int *piVar1;
  int *piVar2;
  
  FUN_0056da60(&DAT_00afeae4,"..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0x110f);
  piVar1 = (int *)(&DAT_00b02d08)[param_1 & 0xfffffff];
  if (piVar1 == (int *)0x0) {
    FUN_0056dac0(&DAT_00afeae4);
    return 0xffffffff;
  }
  if (*piVar1 == 0) {
    FUN_0052dbe0(piVar1[1]);
    piVar1[1] = 0;
  }
  else {
    piVar2 = (int *)(&DAT_00afed08)[piVar1[2]];
    if ((piVar2 != (int *)0x0) && (*piVar2 != 0)) {
      *piVar2 = *piVar2 + -1;
    }
    FUN_00571620(piVar1 + 4);
  }
  FUN_0056e1d0(piVar1);
  (&DAT_00b02d08)[param_1 & 0xfffffff] = 0;
  DAT_00b22da8 = DAT_00b22da8 + -1;
  FUN_0056dac0(&DAT_00afeae4);
  return 0;
}

