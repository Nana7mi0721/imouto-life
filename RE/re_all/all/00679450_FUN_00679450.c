
void FUN_00679450(uint *param_1,undefined4 *param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined1 uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  
  puVar6 = param_2;
  if (5 < param_3) {
    return;
  }
  bVar1 = *(byte *)((int)param_1 + 0xb);
  if (bVar1 == 1) {
    uVar3 = *param_1;
    uVar9 = 0;
    uVar2 = (uint)(byte)(&DAT_0081f144)[param_3];
    iVar8 = 7;
    if (uVar3 <= uVar2) goto LAB_00679663;
    do {
      uVar9 = uVar9 | (*(byte *)((int)puVar6 + (uVar2 >> 3)) >> (7 - ((byte)uVar2 & 7) & 0x1f) & 1)
                      << ((byte)iVar8 & 0x1f);
      if (iVar8 == 0) {
        iVar8 = 7;
        *(char *)param_2 = (char)uVar9;
        param_2 = (undefined4 *)((int)param_2 + 1);
        uVar9 = 0;
      }
      else {
        iVar8 = iVar8 + -1;
      }
      uVar5 = (undefined1)uVar9;
      uVar2 = uVar2 + (byte)(&DAT_0081f14c)[param_3];
    } while (uVar2 < uVar3);
    if (iVar8 == 7) goto LAB_00679663;
  }
  else if (bVar1 == 2) {
    uVar3 = *param_1;
    uVar9 = 0;
    uVar2 = (uint)(byte)(&DAT_0081f144)[param_3];
    iVar8 = 6;
    if (uVar3 <= uVar2) goto LAB_00679663;
    do {
      uVar9 = uVar9 | (*(byte *)((int)puVar6 + (uVar2 >> 2)) >> (((byte)uVar2 & 3) * -2 + 6 & 0x1f)
                      & 3) << ((byte)iVar8 & 0x1f);
      if (iVar8 == 0) {
        iVar8 = 6;
        *(char *)param_2 = (char)uVar9;
        param_2 = (undefined4 *)((int)param_2 + 1);
        uVar9 = 0;
      }
      else {
        iVar8 = iVar8 + -2;
      }
      uVar5 = (undefined1)uVar9;
      uVar2 = uVar2 + (byte)(&DAT_0081f14c)[param_3];
    } while (uVar2 < uVar3);
    if (iVar8 == 6) goto LAB_00679663;
  }
  else {
    uVar3 = *param_1;
    if (bVar1 != 4) {
      uVar9 = (uint)(bVar1 >> 3);
      for (uVar2 = (uint)(byte)(&DAT_0081f144)[param_3]; uVar2 < uVar3;
          uVar2 = uVar2 + (byte)(&DAT_0081f14c)[param_3]) {
        puVar7 = (undefined4 *)(uVar2 * uVar9 + (int)param_2);
        if (puVar6 != puVar7) {
          puVar10 = puVar6;
          for (uVar4 = (uint)(bVar1 >> 5); uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar10 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar10 = puVar10 + 1;
          }
          for (uVar4 = uVar9 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(undefined1 *)puVar10 = *(undefined1 *)puVar7;
            puVar7 = (undefined4 *)((int)puVar7 + 1);
            puVar10 = (undefined4 *)((int)puVar10 + 1);
          }
        }
        puVar6 = (undefined4 *)((int)puVar6 + uVar9);
      }
      goto LAB_00679663;
    }
    uVar2 = (uint)(byte)(&DAT_0081f144)[param_3];
    uVar9 = 0;
    iVar8 = 4;
    if (uVar3 <= uVar2) goto LAB_00679663;
    do {
      uVar9 = uVar9 | (*(byte *)((int)puVar6 + (uVar2 >> 1)) >> (((byte)uVar2 & 1) * -4 + 4 & 0x1f)
                      & 0xf) << ((byte)iVar8 & 0x1f);
      if (iVar8 == 0) {
        iVar8 = 4;
        *(char *)param_2 = (char)uVar9;
        param_2 = (undefined4 *)((int)param_2 + 1);
        uVar9 = 0;
      }
      else {
        iVar8 = iVar8 + -4;
      }
      uVar5 = (undefined1)uVar9;
      uVar2 = uVar2 + (byte)(&DAT_0081f14c)[param_3];
    } while (uVar2 < uVar3);
    if (iVar8 == 4) goto LAB_00679663;
  }
  *(undefined1 *)param_2 = uVar5;
LAB_00679663:
  uVar3 = (((uint)(byte)(&DAT_0081f14c)[param_3] - (uint)(byte)(&DAT_0081f144)[param_3]) + -1 +
          *param_1) / (uint)(byte)(&DAT_0081f14c)[param_3];
  bVar1 = *(byte *)((int)param_1 + 0xb);
  *param_1 = uVar3;
  if (bVar1 < 8) {
    param_1[1] = bVar1 * uVar3 + 7 >> 3;
    return;
  }
  param_1[1] = (bVar1 >> 3) * uVar3;
  return;
}

