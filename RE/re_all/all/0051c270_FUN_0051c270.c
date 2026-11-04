
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0051c270(void)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  int *piVar5;
  
  if (DAT_00a3ce48 == 0x1000) {
    uVar4 = 0;
    piVar5 = &DAT_00a38e44;
    iVar1 = DAT_00a38e44;
    while (iVar1 != 0) {
      piVar5 = piVar5 + 1;
      uVar4 = uVar4 + 1;
      iVar1 = *piVar5;
    }
  }
  else {
    piVar5 = &DAT_00a38e44 + DAT_00a3ce48;
    uVar4 = DAT_00a3ce48;
  }
  puVar3 = (uint *)FUN_0056e050(0x88,"..\\..\\..\\..\\Source\\Library\\Main\\DxGraphics.cpp",0x7c95)
  ;
  *piVar5 = (int)puVar3;
  if (puVar3 == (uint *)0x0) {
    uVar4 = FUN_0056bb10(&DAT_007d550c);
    return uVar4;
  }
  FUN_0056d380(puVar3,0,0x88);
  uVar2 = _DAT_007d5508;
  puVar3[0xb] = _DAT_007d5508;
  puVar3[0x1d] = 0;
  puVar3[0xc] = uVar2;
  puVar3[0x1c] = 0xffffffff;
  puVar3[0xd] = uVar2;
  puVar3[0x1e] = 0;
  puVar3[0xe] = uVar2;
  puVar3[3] = 0x3f800000;
  puVar3[4] = 0x3f800000;
  puVar3[5] = 0x3f800000;
  puVar3[6] = 0x3f800000;
  puVar3[7] = 0x3f800000;
  puVar3[8] = 0x3f800000;
  puVar3[9] = 0x3f800000;
  puVar3[10] = 0x3f800000;
  puVar3[0x17] = _DAT_007d5504;
  puVar3[0x18] = 0;
  puVar3[0x19] = 0;
  puVar3[0x16] = 0x3f800000;
  uVar2 = _DAT_007d103c;
  puVar3[0x1a] = _DAT_007d103c;
  puVar3[0x1b] = uVar2;
  puVar3[0x15] = _DAT_007d5500;
  *puVar3 = DAT_00a3ce4c;
  DAT_00a3ce4c = DAT_00a3ce4c + 1;
  if (0x3fe < (int)DAT_00a3ce4c) {
    DAT_00a3ce4c = 0;
  }
  puVar3[1] = (*puVar3 | 0x2c00) << 0x10 | uVar4;
  DAT_00a3ce44 = DAT_00a3ce44 + 1;
  if (DAT_00a3ce48 == uVar4) {
    DAT_00a3ce48 = DAT_00a3ce48 + 1;
  }
  uVar4 = puVar3[1];
  if ((((-1 < (int)uVar4) && ((uVar4 & 0x7c000000) == 0x2c000000)) && ((uVar4 & 0xffff) < 0x1000))
     && (((piVar5 = (int *)(&DAT_00a38e44)[uVar4 & 0xffff], piVar5 != (int *)0x0 &&
          (*piVar5 * 0x10000 == (uVar4 & 0x3ff0000))) && (piVar5[0x1d] != 1)))) {
    piVar5[0x1d] = 1;
    piVar5[0x1e] = 1;
    DAT_00a3d258 = 1;
    DAT_00a3d360 = 1;
  }
  return puVar3[1];
}

