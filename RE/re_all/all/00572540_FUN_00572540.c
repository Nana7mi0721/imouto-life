
uint FUN_00572540(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint local_604;
  undefined1 local_600 [1536];
  
  if (DAT_00afeae0 == 0) {
    FUN_0056da30(&DAT_00afeae4);
    FUN_005714c0();
    DAT_00afeae0 = 1;
  }
  FUN_0056da60(&DAT_00afeae4,"..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0x1087);
  if (DAT_00b22da8 == 0x8000) {
    FUN_0056dac0(&DAT_00afeae4);
    FUN_0056bb10(&DAT_007d8104);
    return 0;
  }
  uVar4 = 0;
  local_604 = 0;
  if (DAT_00b02d08 != 0) {
    do {
      uVar4 = uVar4 + 1;
    } while ((&DAT_00b02d08)[uVar4] != 0);
    local_604 = uVar4;
  }
  puVar2 = (undefined4 *)
           FUN_0056e030(0x50,"..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0x1099);
  (&DAT_00b02d08)[local_604] = (int)puVar2;
  if (puVar2 == (undefined4 *)0x0) {
    FUN_0056dac0(&DAT_00afeae4);
    FUN_0056bb10(&DAT_007d80cc);
    return 0;
  }
  if (DAT_00b22d8c == 0) {
    piVar1 = puVar2 + 2;
    iVar3 = FUN_00571ef0(param_1,piVar1,local_600,0x600);
    if (iVar3 == 0) {
      iVar3 = FUN_00570f30(puVar2 + 4,(&DAT_00afed08)[*piVar1] + 8,local_600,param_4);
      if (-1 < iVar3) goto LAB_0057278c;
      piVar1 = (int *)(&DAT_00afed08)[*piVar1];
      if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
        *piVar1 = *piVar1 + -1;
      }
    }
    *puVar2 = 0;
    iVar3 = FUN_0052db80(param_1,param_2,1,param_4);
    puVar2[1] = iVar3;
    if (iVar3 == 0) {
LAB_0057274f:
      if ((&DAT_00b02d08)[local_604] != 0) {
        FUN_0056e1d0((&DAT_00b02d08)[local_604]);
      }
      (&DAT_00b02d08)[local_604] = 0;
      FUN_0056dac0(&DAT_00afeae4);
      return 0;
    }
  }
  else {
    iVar3 = FUN_0052db80(param_1,param_2,1,param_4);
    puVar2[1] = iVar3;
    if (iVar3 != 0) {
      *puVar2 = 0;
      goto LAB_00572792;
    }
    piVar1 = puVar2 + 2;
    iVar3 = FUN_00571ef0(param_1,piVar1,local_600,0x600);
    if (iVar3 != 0) goto LAB_0057274f;
    iVar3 = FUN_00570f30(puVar2 + 4,(&DAT_00afed08)[*piVar1] + 8,local_600,param_4);
    if (iVar3 < 0) {
      piVar1 = (int *)(&DAT_00afed08)[*piVar1];
      if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
        *piVar1 = *piVar1 + -1;
      }
      goto LAB_0057274f;
    }
LAB_0057278c:
    *puVar2 = 1;
  }
LAB_00572792:
  DAT_00b22da8 = DAT_00b22da8 + 1;
  FUN_0056dac0(&DAT_00afeae4);
  return local_604 | 0xf0000000;
}

