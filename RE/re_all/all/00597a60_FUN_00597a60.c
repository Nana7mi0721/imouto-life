
undefined4 FUN_00597a60(void)

{
  short *psVar1;
  undefined4 uVar2;
  ushort *puVar3;
  short sVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  ushort *puVar8;
  int iVar9;
  int iVar10;
  ushort *puVar11;
  int iVar12;
  undefined4 *puVar13;
  int local_4;
  
  if (DAT_00e89590 == 1) {
    return 1;
  }
  sVar4 = 0;
  local_4 = 0;
  do {
    iVar10 = 0;
    if (-1 < local_4) {
      do {
        iVar9 = 0;
        if (-1 < iVar10) {
          do {
            iVar12 = 0;
            if (-1 < iVar9) {
              do {
                iVar6 = 0;
                if (-1 < iVar12) {
                  do {
                    if (-1 < iVar6) {
                      psVar1 = &DAT_00e89594 +
                               (iVar6 + (iVar12 + (iVar9 + (iVar10 + local_4 * 4) * 4) * 4) * 4) * 4
                      ;
                      iVar7 = iVar6 + 1;
                      do {
                        *psVar1 = sVar4;
                        sVar4 = sVar4 + 1;
                        psVar1 = psVar1 + 1;
                        iVar7 = iVar7 + -1;
                      } while (iVar7 != 0);
                    }
                    iVar6 = iVar6 + 1;
                  } while (iVar6 <= iVar12);
                }
                iVar12 = iVar12 + 1;
              } while (iVar12 <= iVar9);
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 <= iVar10);
        }
        iVar10 = iVar10 + 1;
      } while (iVar10 <= local_4);
    }
    local_4 = local_4 + 1;
  } while (local_4 < 4);
  sVar4 = 0;
  iVar10 = 0;
  do {
    iVar9 = 0;
    if (-1 < iVar10) {
      do {
        if (-1 < iVar9) {
          psVar1 = &DAT_00e8b594 + (iVar9 + iVar10 * 4) * 4;
          iVar12 = iVar9 + 1;
          do {
            *psVar1 = sVar4;
            sVar4 = sVar4 + 1;
            psVar1 = psVar1 + 1;
            iVar12 = iVar12 + -1;
          } while (iVar12 != 0);
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 <= iVar10);
    }
    iVar10 = iVar10 + 1;
  } while (iVar10 < 4);
  sVar4 = 0;
  iVar9 = 0;
  iVar10 = 0;
  do {
    iVar12 = 0;
    if (-1 < iVar10) {
      do {
        if (-1 < iVar12) {
          psVar1 = &DAT_00e8b614 + (iVar9 + iVar12) * 3;
          iVar6 = iVar12 + 1;
          do {
            *psVar1 = sVar4;
            sVar4 = sVar4 + 1;
            psVar1 = psVar1 + 1;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
        }
        iVar12 = iVar12 + 1;
      } while (iVar12 <= iVar10);
    }
    iVar9 = iVar9 + 3;
    iVar10 = iVar10 + 1;
  } while (iVar9 < 9);
  DAT_00e8c778 = 0;
  DAT_00e8c77c = (ushort *)0x0;
  DAT_00e8bee0 = 0;
  if (DAT_00f3a138 == 0) {
    DAT_00f3a138 = 1;
    FUN_005702e0(&DAT_00892cd0,&DAT_00892cd0);
  }
  uVar2 = FUN_00570180(&DAT_00892cd0,0);
  DAT_00e8bee0 = FUN_0056e030(uVar2,
                              "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxGraphicsD3D9.cpp",
                              0x63c);
  if (DAT_00e8bee0 != 0) {
    FUN_00570180(&DAT_00892cd0,DAT_00e8bee0);
    FUN_0056e7a0(&DAT_00e8b650);
    iVar10 = FUN_0056e970(&DAT_00e8b650,DAT_00e8bee0,uVar2,0,0,0,0);
    if (iVar10 == 0) {
      if (DAT_00f3a134 == 0) {
        DAT_00f3a134 = 1;
        FUN_005702e0(&DAT_00891148,&DAT_00891148);
      }
      uVar2 = FUN_00570180(&DAT_00891148,0);
      DAT_00e8c77c = (ushort *)
                     FUN_0056e030(uVar2,
                                  "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxGraphicsD3D9.cpp"
                                  ,0x659);
      if (DAT_00e8c77c != (ushort *)0x0) {
        FUN_00570180(&DAT_00891148,DAT_00e8c77c);
        puVar11 = DAT_00e8c77c + 0x100;
        puVar8 = &DAT_00e8cf84;
        puVar13 = &DAT_00e8c788;
        iVar10 = 0x80;
        puVar3 = DAT_00e8c77c;
        do {
          uVar5 = 0;
          if (*puVar3 != 0) {
            puVar13[-2] = puVar11;
            uVar5 = *puVar3;
            puVar11 = (ushort *)((int)puVar11 + (uint)uVar5);
          }
          puVar8[-2] = uVar5;
          uVar5 = 0;
          if (puVar3[1] != 0) {
            puVar13[-1] = puVar11;
            uVar5 = puVar3[1];
            puVar11 = (ushort *)((int)puVar11 + (uint)uVar5);
          }
          puVar8[-1] = uVar5;
          uVar5 = 0;
          if (puVar3[2] != 0) {
            *puVar13 = puVar11;
            uVar5 = puVar3[2];
            puVar11 = (ushort *)((int)puVar11 + (uint)uVar5);
          }
          *puVar8 = uVar5;
          uVar5 = 0;
          if (puVar3[3] != 0) {
            puVar13[1] = puVar11;
            uVar5 = puVar3[3];
            puVar11 = (ushort *)((int)puVar11 + (uint)uVar5);
          }
          puVar8[1] = uVar5;
          puVar3 = puVar3 + 4;
          puVar13 = puVar13 + 4;
          puVar8 = puVar8 + 4;
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
        if (DAT_00f3a130 == 0) {
          DAT_00f3a130 = 1;
          FUN_005702e0(&DAT_00889f20,&DAT_00889f20);
        }
        uVar2 = FUN_00570180(&DAT_00889f20,0);
        DAT_00e8c778 = FUN_0056e030(uVar2,
                                    "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxGraphicsD3D9.cpp"
                                    ,0x67a);
        if (DAT_00e8c778 != 0) {
          FUN_00570180(&DAT_00889f20,DAT_00e8c778);
          FUN_0056e7a0(&DAT_00e8bee8);
          iVar10 = FUN_0056e970(&DAT_00e8bee8,DAT_00e8c778,uVar2,0,0,0,0);
          if (iVar10 == 0) {
            DAT_00e89590 = 1;
            return 1;
          }
        }
      }
    }
    if (DAT_00e8bee0 != 0) {
      FUN_0056e1d0(DAT_00e8bee0);
      DAT_00e8bee0 = 0;
    }
  }
  if (DAT_00e8c778 != 0) {
    FUN_0056e1d0(DAT_00e8c778);
    DAT_00e8c778 = 0;
  }
  if (DAT_00e8c77c != (ushort *)0x0) {
    FUN_0056e1d0(DAT_00e8c77c);
    DAT_00e8c77c = (ushort *)0x0;
  }
  return 0;
}

