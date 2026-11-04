
uint FUN_0067c870(uint param_1,byte *param_2,uint param_3)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  byte *pbVar19;
  uint uVar20;
  
  uVar20 = param_1 >> 0x10;
  param_1 = param_1 & 0xffff;
  if (param_3 == 1) {
    param_1 = param_1 + *param_2;
    if (0xfff0 < param_1) {
      param_1 = param_1 - 0xfff1;
    }
    uVar20 = uVar20 + param_1;
    if (0xfff0 < uVar20) {
      uVar20 = uVar20 - 0xfff1;
    }
    return uVar20 << 0x10 | param_1;
  }
  if (param_2 == (byte *)0x0) {
    return 1;
  }
  if (param_3 < 0x10) {
    if (param_3 != 0) {
      do {
        param_1 = param_1 + *param_2;
        param_2 = param_2 + 1;
        uVar20 = uVar20 + param_1;
        param_3 = param_3 - 1;
      } while (param_3 != 0);
    }
    if (0xfff0 < param_1) {
      param_1 = param_1 - 0xfff1;
    }
    return uVar20 % 0xfff1 << 0x10 | param_1;
  }
  pbVar19 = param_2;
  if (0x15af < param_3) {
    param_2 = (byte *)(param_3 / 0x15b0);
    do {
      param_3 = param_3 - 0x15b0;
      iVar17 = 0x15b;
      do {
        iVar2 = param_1 + *pbVar19;
        iVar3 = iVar2 + (uint)pbVar19[1];
        iVar4 = iVar3 + (uint)pbVar19[2];
        iVar5 = iVar4 + (uint)pbVar19[3];
        iVar6 = iVar5 + (uint)pbVar19[4];
        iVar7 = iVar6 + (uint)pbVar19[5];
        iVar8 = iVar7 + (uint)pbVar19[6];
        iVar9 = iVar8 + (uint)pbVar19[7];
        iVar10 = iVar9 + (uint)pbVar19[8];
        iVar11 = iVar10 + (uint)pbVar19[9];
        iVar12 = iVar11 + (uint)pbVar19[10];
        iVar13 = iVar12 + (uint)pbVar19[0xb];
        iVar14 = iVar13 + (uint)pbVar19[0xc];
        iVar15 = iVar14 + (uint)pbVar19[0xd];
        pbVar1 = pbVar19 + 0xf;
        iVar16 = iVar15 + (uint)pbVar19[0xe];
        pbVar19 = pbVar19 + 0x10;
        param_1 = iVar16 + (uint)*pbVar1;
        uVar20 = uVar20 + iVar2 + iVar3 + iVar4 + iVar5 + iVar6 + iVar7 + iVar8 + iVar9 + iVar10 +
                 iVar11 + iVar12 + iVar13 + iVar14 + iVar15 + iVar16 + param_1;
        iVar17 = iVar17 + -1;
      } while (iVar17 != 0);
      param_1 = param_1 % 0xfff1;
      uVar20 = uVar20 % 0xfff1;
      param_2 = (byte *)((int)param_2 - 1);
    } while (param_2 != (byte *)0x0);
  }
  if (param_3 != 0) {
    if (0xf < param_3) {
      uVar18 = param_3 >> 4;
      do {
        iVar17 = param_1 + *pbVar19;
        iVar2 = iVar17 + (uint)pbVar19[1];
        iVar3 = iVar2 + (uint)pbVar19[2];
        iVar4 = iVar3 + (uint)pbVar19[3];
        iVar5 = iVar4 + (uint)pbVar19[4];
        iVar6 = iVar5 + (uint)pbVar19[5];
        iVar7 = iVar6 + (uint)pbVar19[6];
        iVar8 = iVar7 + (uint)pbVar19[7];
        iVar9 = iVar8 + (uint)pbVar19[8];
        iVar10 = iVar9 + (uint)pbVar19[9];
        iVar11 = iVar10 + (uint)pbVar19[10];
        iVar12 = iVar11 + (uint)pbVar19[0xb];
        iVar13 = iVar12 + (uint)pbVar19[0xc];
        iVar14 = iVar13 + (uint)pbVar19[0xd];
        iVar15 = iVar14 + (uint)pbVar19[0xe];
        param_3 = param_3 - 0x10;
        param_1 = iVar15 + (uint)pbVar19[0xf];
        uVar20 = uVar20 + iVar17 + iVar2 + iVar3 + iVar4 + iVar5 + iVar6 + iVar7 + iVar8 + iVar9 +
                 iVar10 + iVar11 + iVar12 + iVar13 + iVar14 + iVar15 + param_1;
        pbVar19 = pbVar19 + 0x10;
        uVar18 = uVar18 - 1;
      } while (uVar18 != 0);
    }
    if (param_3 != 0) {
      do {
        param_1 = param_1 + *pbVar19;
        pbVar19 = pbVar19 + 1;
        uVar20 = uVar20 + param_1;
        param_3 = param_3 - 1;
      } while (param_3 != 0);
    }
    param_1 = param_1 % 0xfff1;
    uVar20 = uVar20 % 0xfff1;
  }
  return uVar20 << 0x10 | param_1;
}

