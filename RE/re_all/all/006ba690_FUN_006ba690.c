
void FUN_006ba690(uint param_1)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  int local_c;
  
  iVar12 = *(int *)(param_1 + 0xe8);
  iVar13 = 0;
  if (0 < iVar12) {
    iVar3 = *(int *)(param_1 + 0xa8);
    piVar11 = *(int **)(param_1 + 0xd8);
    if (*(char *)(param_1 + 0x36a) == '\x01') {
      if (0 < iVar12) {
        do {
          iVar13 = *piVar11;
          piVar11 = piVar11 + 1;
          iVar12 = iVar12 + -1;
          *(uint *)(iVar3 + iVar13 * 4) = *(uint *)(iVar3 + iVar13 * 4) & 0xffffffc3;
        } while (iVar12 != 0);
        return;
      }
    }
    else {
      iVar5 = param_1 + 0xc9b4;
      uVar6 = FUN_006bf110(iVar5);
      local_c = 0;
      if (0 < iVar12) {
        do {
          iVar7 = FUN_006ba1e0(iVar5);
          bVar4 = iVar7 < 0x1021;
          piVar8 = piVar11 + iVar13;
          do {
            iVar9 = *piVar8;
            piVar8 = piVar8 + 1;
            puVar2 = (uint *)(iVar3 + iVar9 * 4);
            iVar13 = iVar13 + 1;
            *puVar2 = *puVar2 & 0xffffffc3 | (uVar6 & 0xf) * 4;
            local_c = local_c + uVar6;
            iVar7 = iVar7 + -1;
            if (iVar7 < 1) break;
          } while (iVar13 < iVar12);
          if ((bVar4) || (iVar12 <= iVar13)) {
            uVar6 = (uint)(uVar6 == 0);
          }
          else {
            uVar6 = FUN_006bf110(iVar5);
          }
        } while (iVar13 < iVar12);
      }
      if ((*(char *)(param_1 + 0x36a) == '\x03') && (0 < local_c)) {
        iVar13 = 0;
        if ((*(byte *)(iVar3 + *piVar11 * 4) & 0x3c) == 0) {
          piVar8 = piVar11;
          do {
            piVar1 = piVar8 + 1;
            piVar8 = piVar8 + 1;
            iVar13 = iVar13 + 1;
          } while ((*(byte *)(iVar3 + *piVar1 * 4) & 0x3c) == 0);
        }
        param_1 = FUN_006bf110(iVar5);
        do {
          iVar7 = FUN_006ba1e0(iVar5);
          if (iVar13 < iVar12) {
            piVar8 = piVar11 + iVar13;
            iVar9 = iVar7;
            do {
              uVar6 = *(uint *)(iVar3 + *piVar8 * 4);
              iVar10 = iVar9;
              if ((uVar6 & 0x3c) != 0) {
                iVar10 = iVar9 + -1;
                if (iVar9 < 1) break;
                *(uint *)(iVar3 + *piVar8 * 4) =
                     ((uint)((byte)uVar6 & 0xfc) + param_1 * 4 ^ uVar6) & 0x3c ^ uVar6;
              }
              iVar13 = iVar13 + 1;
              piVar8 = piVar8 + 1;
              iVar9 = iVar10;
            } while (iVar13 < iVar12);
          }
          if ((iVar7 < 0x1021) || (iVar12 <= iVar13)) {
            param_1 = (uint)(param_1 == 0);
          }
          else {
            param_1 = FUN_006bf110(iVar5);
          }
          if (iVar12 <= iVar13) {
            return;
          }
        } while( true );
      }
    }
  }
  return;
}

