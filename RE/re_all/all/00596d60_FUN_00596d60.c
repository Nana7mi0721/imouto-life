
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00596d60(void)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  int unaff_ESI;
  uint uVar7;
  
  if (*(short *)(unaff_ESI + 0x5e) == 1) {
    iVar2 = (**(code **)(unaff_ESI + 0xc))(*(undefined4 *)(unaff_ESI + 0x24));
    iVar2 = iVar2 - *(int *)(unaff_ESI + 0x30);
    if (iVar2 != *(int *)(unaff_ESI + 0x34)) {
      iVar2 = *(int *)(unaff_ESI + 0x34) - iVar2;
      if (*(int *)(unaff_ESI + 0x450) < iVar2) {
        iVar2 = *(int *)(unaff_ESI + 0x450);
      }
      (**(code **)(unaff_ESI + 0x14))
                (*(undefined4 *)(unaff_ESI + 0x44c),iVar2,1,*(undefined4 *)(unaff_ESI + 0x24));
      *(int *)(unaff_ESI + 0x454) = iVar2;
      return 0;
    }
  }
  else {
    if (*(short *)(unaff_ESI + 0x5e) != 3) {
      return 0;
    }
    iVar2 = (**(code **)(unaff_ESI + 0xc))(*(undefined4 *)(unaff_ESI + 0x24));
    iVar2 = iVar2 - *(int *)(unaff_ESI + 0x30);
    if (iVar2 != *(int *)(unaff_ESI + 0x34)) {
      uVar7 = *(int *)(unaff_ESI + 0x34) - iVar2;
      if (*(uint *)(unaff_ESI + 0x4e) < uVar7) {
        uVar7 = *(uint *)(unaff_ESI + 0x4e);
      }
      (**(code **)(unaff_ESI + 0x14))
                (*(undefined4 *)(unaff_ESI + 0x4a),uVar7,1,*(undefined4 *)(unaff_ESI + 0x24));
      iVar2 = (int)uVar7 / (int)(uint)*(ushort *)(unaff_ESI + 0x6a);
      puVar3 = *(undefined2 **)(unaff_ESI + 0x44c);
      pfVar5 = *(float **)(unaff_ESI + 0x4a);
      if (iVar2 != 0) {
        iVar6 = iVar2;
        do {
          iVar4 = 0;
          if (*(short *)(unaff_ESI + 0x60) != 0) {
            do {
              iVar1 = (int)ROUND(*pfVar5 * (float)_DAT_00805408);
              if (iVar1 < -0x8000) {
                *puVar3 = 0x8000;
              }
              else if (iVar1 < 0x8000) {
                *puVar3 = (short)iVar1;
              }
              else {
                *puVar3 = 0x7fff;
              }
              iVar4 = iVar4 + 1;
              puVar3 = puVar3 + 1;
              pfVar5 = pfVar5 + 1;
            } while (iVar4 < (int)(uint)*(ushort *)(unaff_ESI + 0x60));
          }
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      *(uint *)(unaff_ESI + 0x454) = (uint)*(ushort *)(unaff_ESI + 0x44) * iVar2;
      return 0;
    }
  }
  return 0xffffffff;
}

