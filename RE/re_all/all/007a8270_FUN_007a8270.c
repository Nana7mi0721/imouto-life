
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_007a8270(int param_1,int param_2,uint param_3,int *param_4)

{
  int *piVar1;
  uint *puVar2;
  undefined **ppuVar3;
  int iVar4;
  short sVar5;
  uint uVar6;
  ushort uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  undefined **ppuVar12;
  bool bVar13;
  float10 fVar14;
  float10 fVar15;
  float10 fVar16;
  
  fVar14 = (float10)_DAT_007d5344;
  uVar6 = param_3;
  if (2 < param_1) {
    iVar9 = param_1 * 4;
    do {
      sVar5 = (short)param_2;
      if (param_2 < param_1) {
        ppuVar12 = &PTR_DAT_0083dc68 + param_2;
        uVar8 = *(uint *)((&PTR_DAT_0083dc68)[param_2] + iVar9);
        uVar10 = *(uint *)((&PTR_DAT_0083dc6c)[param_2] + iVar9);
        if ((uVar6 < uVar8) || (uVar10 <= uVar6)) {
          bVar13 = uVar10 <= uVar6;
          uVar6 = uVar6 - (uVar10 & -(uint)bVar13);
          do {
            ppuVar3 = ppuVar12 + -1;
            ppuVar12 = ppuVar12 + -1;
            param_2 = param_2 + -1;
          } while (uVar6 < *(uint *)(*ppuVar3 + iVar9));
          uVar6 = uVar6 - *(uint *)(*ppuVar3 + iVar9);
          uVar7 = (ushort)-(uint)bVar13;
          uVar7 = (uVar7 - (short)param_2) + sVar5 ^ uVar7;
          goto LAB_007a8379;
        }
        *param_4 = 0;
        uVar6 = uVar6 - uVar8;
      }
      else {
        iVar4 = *(int *)((int)&PTR_DAT_0083dc68 + iVar9);
        iVar11 = (int)&PTR_DAT_0083dc68 + iVar9;
        uVar8 = *(uint *)(iVar4 + 4 + param_2 * 4);
        uVar10 = -(uint)(uVar8 <= uVar6);
        uVar6 = uVar6 - (uVar10 & uVar8);
        if (uVar6 < *(uint *)(iVar9 + iVar4)) {
          param_2 = param_1;
          do {
            piVar1 = (int *)(iVar11 + -4);
            iVar11 = iVar11 + -4;
            param_2 = param_2 + -1;
            uVar8 = *(uint *)(iVar9 + *piVar1);
          } while (uVar6 < uVar8);
        }
        else {
          iVar11 = iVar4 + param_2 * 4;
          uVar8 = *(uint *)(iVar4 + param_2 * 4);
          while (uVar6 < uVar8) {
            puVar2 = (uint *)(iVar11 + -4);
            iVar11 = iVar11 + -4;
            param_2 = param_2 + -1;
            uVar8 = *puVar2;
          }
        }
        uVar6 = uVar6 - uVar8;
        uVar7 = (ushort)uVar10;
        uVar7 = (uVar7 - (short)param_2) + sVar5 ^ uVar7;
LAB_007a8379:
        param_3 = (uint)(short)uVar7;
        *param_4 = param_3;
        fVar14 = (float10)(int)param_3 * (float10)(int)param_3 + fVar14;
      }
      param_4 = param_4 + 1;
      param_1 = param_1 + -1;
      iVar9 = iVar9 + -4;
    } while (2 < param_1);
  }
  uVar8 = param_2 * 2 + 1;
  uVar10 = -(uint)(uVar8 <= uVar6);
  iVar9 = uVar6 - (uVar10 & uVar8);
  uVar6 = iVar9 + 1U >> 1;
  if (uVar6 != 0) {
    iVar9 = iVar9 + uVar6 * -2 + 1;
  }
  uVar7 = (ushort)uVar10;
  iVar11 = (int)(short)((uVar7 - (short)uVar6) + (short)param_2 ^ uVar7);
  *param_4 = iVar11;
  fVar15 = (float10)iVar11;
  iVar9 = (int)(short)(-(short)iVar9 + (short)uVar6 ^ -(short)iVar9);
  param_4[1] = iVar9;
  fVar16 = (float10)iVar9;
  return fVar16 * fVar16 + fVar15 * fVar15 + fVar14;
}

