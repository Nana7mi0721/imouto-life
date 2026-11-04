
undefined4 FUN_00541e90(void)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined1 *puVar9;
  int iVar10;
  uint uVar11;
  
  if (DAT_00a52a44 != 1) {
    iVar1 = FUN_005e2310();
    if (iVar1 == 0) {
      iVar1 = -0x200;
      do {
        if (iVar1 < 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = 0xff;
          if (iVar1 < 0x100) {
            iVar5 = iVar1;
          }
        }
        (&DAT_00a524f8)[iVar1] = (char)iVar5;
        iVar1 = iVar1 + 1;
      } while (iVar1 < 0x300);
      iVar10 = -0x4a7e0;
      iVar8 = -0x409300;
      piVar2 = &DAT_00a512f8;
      iVar5 = -0x331200;
      iVar6 = 0x1a0400;
      iVar1 = 0xc8300;
      do {
        *piVar2 = iVar1;
        piVar2[-0x100] = iVar5;
        piVar2[0x100] = iVar6;
        piVar2[0x200] = iVar8;
        piVar2[0x300] = iVar10;
        iVar1 = iVar1 + -0x1906;
        iVar5 = iVar5 + 0x6624;
        iVar8 = iVar8 + 0x8126;
        iVar10 = iVar10 + 0x4a7e;
        iVar6 = iVar6 + -0x3408;
        piVar2 = piVar2 + 1;
      } while (-0xc8300 < iVar1);
      uVar11 = 0;
      uVar7 = 0;
      puVar9 = &DAT_00a62a60;
      do {
        uVar4 = 0;
        do {
          puVar9[uVar4 - 0x10000] = (char)((uVar4 * uVar11) / 0xff);
          if (uVar4 == 0) {
            *puVar9 = 0;
          }
          else {
            uVar3 = uVar7 / uVar4;
            if (0xff < uVar3) {
              uVar3 = 0xff;
            }
            puVar9[uVar4] = (char)uVar3;
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < 0x100);
        uVar11 = uVar11 + 1;
        puVar9 = puVar9 + 0x100;
        uVar7 = uVar7 + 0xff;
      } while (uVar11 < 0x100);
      DAT_00a52a44 = 1;
      return 0;
    }
  }
  return 0xffffffff;
}

