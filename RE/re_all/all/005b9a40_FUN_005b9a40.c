
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005b9a40(undefined4 *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  iVar2 = FUN_0056d3d0(&DAT_00a38e2c,&DAT_00f07660,0x10);
  if (((iVar2 == 0) && (iVar2 = FUN_0056d3d0(param_1,&DAT_00f0761c,0x44), iVar2 == 0)) &&
     (DAT_00ef7324 == 0)) {
    return 0;
  }
  iVar2 = *(int *)(DAT_00ef1b84 + 8);
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  puVar4 = param_1;
  puVar5 = &DAT_00f0761c;
  for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  FUN_0056d420(&DAT_00f07660,&DAT_00a38e2c,0x10);
  *(undefined4 *)(iVar2 + 0x2a0) = *param_1;
  *(undefined4 *)(iVar2 + 0x2a4) = param_1[1];
  *(undefined4 *)(iVar2 + 0x2a8) = param_1[2];
  *(undefined4 *)(iVar2 + 0x2ac) = param_1[3];
  *(undefined4 *)(iVar2 + 0x2b0) = param_1[8];
  *(undefined4 *)(iVar2 + 0x2b4) = param_1[9];
  *(undefined4 *)(iVar2 + 0x2b8) = param_1[10];
  *(undefined4 *)(iVar2 + 700) = param_1[0xb];
  fVar1 = _DAT_007d9a84;
  if (_DAT_007d9a84 <= (float)param_1[0x10]) {
    fVar1 = (float)param_1[0x10];
  }
  *(float *)(iVar2 + 0x2d0) = fVar1;
  *(undefined4 *)(iVar2 + 0x2d4) = _DAT_00f07660;
  *(undefined4 *)(iVar2 + 0x2d8) = _DAT_00f07664;
  *(undefined4 *)(iVar2 + 0x2dc) = _DAT_00f07668;
  *(undefined4 *)(DAT_00ef1b84 + 0xc) = 1;
  FUN_005b96d0();
  DAT_00ef72cc = 1;
  return 0;
}

