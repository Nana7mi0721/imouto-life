
void FUN_0067fc50(int *param_1,int *param_2)

{
  ushort *puVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  short *psVar13;
  uint uVar14;
  undefined4 *puVar15;
  int iVar16;
  uint uVar17;
  int local_1c;
  ushort *local_14;
  
  iVar9 = (int)param_1;
  iVar3 = *param_2;
  iVar4 = param_2[1];
  piVar5 = (int *)param_2[2];
  iVar11 = *piVar5;
  iVar6 = piVar5[1];
  uVar17 = piVar5[4];
  iVar7 = piVar5[2];
  local_1c = 0;
  puVar15 = (undefined4 *)((int)param_1 + 0xb3c);
  for (iVar12 = 8; iVar12 != 0; iVar12 = iVar12 + -1) {
    *puVar15 = 0;
    puVar15 = puVar15 + 1;
  }
  *(undefined2 *)
   (iVar3 + 2 + *(int *)((int)param_1 + 0xb5c + *(int *)((int)param_1 + 0x1454) * 4) * 4) = 0;
  iVar12 = *(int *)((int)param_1 + 0x1454) + 1;
  if (iVar12 < 0x23d) {
    param_1 = (int *)((int)param_1 + 0xb5c + iVar12 * 4);
    local_14 = (ushort *)(0x23d - iVar12);
    iVar12 = iVar12 + (int)local_14;
    do {
      iVar8 = *param_1;
      uVar10 = *(ushort *)(iVar3 + 2 + (uint)*(ushort *)(iVar3 + 2 + iVar8 * 4) * 4) + 1;
      if ((int)uVar17 < (int)uVar10) {
        local_1c = local_1c + 1;
        uVar10 = uVar17;
      }
      *(short *)(iVar3 + 2 + iVar8 * 4) = (short)uVar10;
      if (iVar8 <= iVar4) {
        psVar13 = (short *)(iVar9 + 0xb3c + uVar10 * 2);
        *psVar13 = *psVar13 + 1;
        iVar16 = 0;
        if (iVar7 <= iVar8) {
          iVar16 = *(int *)(iVar6 + (iVar8 - iVar7) * 4);
        }
        uVar14 = (uint)*(ushort *)(iVar3 + iVar8 * 4);
        *(int *)(iVar9 + 0x16a8) = *(int *)(iVar9 + 0x16a8) + (uVar10 + iVar16) * uVar14;
        if (iVar11 != 0) {
          *(uint *)(iVar9 + 0x16ac) =
               *(int *)(iVar9 + 0x16ac) +
               ((uint)*(ushort *)(iVar11 + 2 + iVar8 * 4) + iVar16) * uVar14;
        }
      }
      param_1 = param_1 + 1;
      local_14 = (ushort *)((int)local_14 + -1);
    } while (local_14 != (ushort *)0x0);
    if (local_1c != 0) {
      do {
        iVar11 = uVar17 - 1;
        psVar13 = (short *)(iVar9 + 0xb3c + iVar11 * 2);
        sVar2 = *(short *)(iVar9 + 0xb3c + iVar11 * 2);
        while (sVar2 == 0) {
          psVar13 = psVar13 + -1;
          iVar11 = iVar11 + -1;
          sVar2 = *psVar13;
        }
        psVar13 = (short *)(iVar9 + 0xb3c + iVar11 * 2);
        *psVar13 = *psVar13 + -1;
        psVar13 = (short *)(iVar9 + 0xb3e + iVar11 * 2);
        *psVar13 = *psVar13 + 2;
        psVar13 = (short *)(iVar9 + 0xb3c + uVar17 * 2);
        *psVar13 = *psVar13 + -1;
        local_1c = local_1c + -2;
      } while (0 < local_1c);
      if (uVar17 != 0) {
        local_14 = (ushort *)(iVar9 + 0xb3c + uVar17 * 2);
        param_2 = (int *)iVar12;
        do {
          uVar10 = (uint)*local_14;
          if (uVar10 != 0) {
            iVar11 = iVar9 + 0xb5c + iVar12 * 4;
            param_1 = (int *)uVar10;
            do {
              iVar6 = *(int *)(iVar11 + -4);
              iVar12 = (int)param_2 + -1;
              iVar11 = iVar11 + -4;
              if (iVar6 <= iVar4) {
                puVar1 = (ushort *)(iVar3 + 2 + iVar6 * 4);
                uVar10 = (uint)*puVar1;
                if (uVar10 != uVar17) {
                  *(uint *)(iVar9 + 0x16a8) =
                       *(int *)(iVar9 + 0x16a8) +
                       (uVar17 - uVar10) * (uint)*(ushort *)(iVar3 + iVar6 * 4);
                  *puVar1 = (ushort)uVar17;
                }
                uVar10 = (int)param_1 - 1;
                param_1 = (int *)uVar10;
              }
              param_2 = (int *)iVar12;
            } while (uVar10 != 0);
          }
          uVar17 = uVar17 - 1;
          local_14 = local_14 + -1;
        } while (uVar17 != 0);
      }
    }
  }
  return;
}

