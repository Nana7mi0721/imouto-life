
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005b6ca0(void)

{
  short *psVar1;
  undefined4 uVar2;
  ushort *puVar3;
  short sVar4;
  int iVar5;
  ushort *puVar6;
  ushort *puVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  ushort *puVar12;
  int iVar13;
  int local_4;
  
  if (DAT_00f203b0 == 1) {
    return 1;
  }
  sVar4 = 0;
  local_4 = 0;
  do {
    iVar11 = 0;
    if (-1 < local_4) {
      do {
        iVar10 = 0;
        if (-1 < iVar11) {
          do {
            iVar13 = 0;
            if (-1 < iVar10) {
              do {
                iVar5 = 0;
                if (-1 < iVar13) {
                  do {
                    if (-1 < iVar5) {
                      psVar1 = (short *)(&DAT_00f203b4 +
                                        (iVar5 + (iVar13 + (iVar10 + (iVar11 + local_4 * 4) * 4) * 4
                                                 ) * 4) * 8);
                      iVar9 = iVar5 + 1;
                      do {
                        *psVar1 = sVar4;
                        sVar4 = sVar4 + 1;
                        psVar1 = psVar1 + 1;
                        iVar9 = iVar9 + -1;
                      } while (iVar9 != 0);
                    }
                    iVar5 = iVar5 + 1;
                  } while (iVar5 <= iVar13);
                }
                iVar13 = iVar13 + 1;
              } while (iVar13 <= iVar10);
            }
            iVar10 = iVar10 + 1;
          } while (iVar10 <= iVar11);
        }
        iVar11 = iVar11 + 1;
      } while (iVar11 <= local_4);
    }
    local_4 = local_4 + 1;
  } while (local_4 < 4);
  sVar4 = 0;
  iVar11 = 0;
  do {
    iVar10 = 0;
    if (-1 < iVar11) {
      do {
        if (-1 < iVar10) {
          psVar1 = &DAT_00f223b4 + (iVar10 + iVar11 * 4) * 4;
          iVar13 = iVar10 + 1;
          do {
            *psVar1 = sVar4;
            sVar4 = sVar4 + 1;
            psVar1 = psVar1 + 1;
            iVar13 = iVar13 + -1;
          } while (iVar13 != 0);
        }
        iVar10 = iVar10 + 1;
      } while (iVar10 <= iVar11);
    }
    iVar11 = iVar11 + 1;
  } while (iVar11 < 4);
  sVar4 = 0;
  iVar11 = 0;
  iVar10 = 0;
  do {
    iVar13 = 0;
    if (-1 < iVar11) {
      do {
        if (-1 < iVar13) {
          psVar1 = &DAT_00f22434 + (iVar10 + iVar13) * 3;
          iVar5 = iVar13 + 1;
          do {
            *psVar1 = sVar4;
            sVar4 = sVar4 + 1;
            psVar1 = psVar1 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
        iVar13 = iVar13 + 1;
      } while (iVar13 <= iVar11);
    }
    iVar10 = iVar10 + 3;
    iVar11 = iVar11 + 1;
  } while (iVar10 < 9);
  DAT_00f23510 = 0;
  DAT_00f23514 = (ushort *)0x0;
  DAT_00f2246c = (ushort *)0x0;
  if (DAT_00f3a174 == 0) {
    DAT_00f3a174 = 1;
    FUN_005702e0(&DAT_0095bbe0,&DAT_0095bbe0);
  }
  uVar2 = FUN_00570180(&DAT_0095bbe0,0);
  DAT_00f2246c = (ushort *)
                 FUN_0056e030(uVar2,
                              "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxGraphicsD3D11.cpp",
                              0x5c1);
  if (DAT_00f2246c != (ushort *)0x0) {
    FUN_00570180(&DAT_0095bbe0,DAT_00f2246c);
    puVar7 = DAT_00f2246c + 0x102;
    puVar6 = puVar7;
    if (*DAT_00f2246c != 0) {
      DAT_00f22474 = (uint)*DAT_00f2246c;
      puVar6 = (ushort *)((int)puVar7 + (uint)*DAT_00f2246c);
      DAT_00f22470 = puVar7;
    }
    puVar7 = puVar6;
    if (DAT_00f2246c[1] != 0) {
      DAT_00f2247c = (uint)DAT_00f2246c[1];
      puVar7 = (ushort *)((int)puVar6 + (uint)DAT_00f2246c[1]);
      DAT_00f22478 = puVar6;
    }
    puVar6 = puVar7;
    if (DAT_00f2246c[2] != 0) {
      _DAT_00f22484 = (uint)DAT_00f2246c[2];
      puVar6 = (ushort *)((int)puVar7 + (uint)DAT_00f2246c[2]);
      _DAT_00f22480 = puVar7;
    }
    puVar7 = puVar6;
    if (DAT_00f2246c[3] != 0) {
      _DAT_00f2248c = (uint)DAT_00f2246c[3];
      puVar7 = (ushort *)((int)puVar6 + (uint)DAT_00f2246c[3]);
      _DAT_00f22488 = puVar6;
    }
    puVar6 = puVar7;
    if (DAT_00f2246c[4] != 0) {
      _DAT_00f22494 = (uint)DAT_00f2246c[4];
      puVar6 = (ushort *)((int)puVar7 + (uint)DAT_00f2246c[4]);
      _DAT_00f22490 = puVar7;
    }
    puVar7 = puVar6;
    if (DAT_00f2246c[5] != 0) {
      _DAT_00f2249c = (uint)DAT_00f2246c[5];
      puVar7 = (ushort *)((int)puVar6 + (uint)DAT_00f2246c[5]);
      _DAT_00f22498 = puVar6;
    }
    puVar6 = puVar7;
    if (DAT_00f2246c[6] != 0) {
      _DAT_00f224a4 = (uint)DAT_00f2246c[6];
      puVar6 = (ushort *)((int)puVar7 + (uint)DAT_00f2246c[6]);
      _DAT_00f224a0 = puVar7;
    }
    puVar7 = DAT_00f2246c + 7;
    puVar8 = &DAT_00f224b0;
    iVar11 = 7;
    do {
      if (*puVar7 != 0) {
        puVar8[-2] = puVar6;
        puVar8[-1] = (uint)*puVar7;
        puVar6 = (ushort *)((int)puVar6 + (uint)*puVar7);
      }
      if (puVar7[1] != 0) {
        *puVar8 = puVar6;
        puVar8[1] = (uint)puVar7[1];
        puVar6 = (ushort *)((int)puVar6 + (uint)puVar7[1]);
      }
      puVar8 = puVar8 + 4;
      puVar7 = puVar7 + 2;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    puVar8 = &DAT_00f22520;
    iVar11 = 0x38;
    do {
      puVar3 = puVar7;
      if (*puVar3 != 0) {
        puVar8[-2] = puVar6;
        puVar8[-1] = (uint)*puVar3;
        puVar6 = (ushort *)((int)puVar6 + (uint)*puVar3);
      }
      if (puVar3[1] != 0) {
        *puVar8 = puVar6;
        puVar8[1] = (uint)puVar3[1];
        puVar6 = (ushort *)((int)puVar6 + (uint)puVar3[1]);
      }
      if (puVar3[2] != 0) {
        puVar8[2] = puVar6;
        puVar8[3] = (uint)puVar3[2];
        puVar6 = (ushort *)((int)puVar6 + (uint)puVar3[2]);
      }
      if (puVar3[3] != 0) {
        puVar8[4] = puVar6;
        puVar8[5] = (uint)puVar3[3];
        puVar6 = (ushort *)((int)puVar6 + (uint)puVar3[3]);
      }
      puVar8 = puVar8 + 8;
      puVar7 = puVar3 + 4;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    puVar12 = puVar6;
    if (*puVar7 != 0) {
      _DAT_00f22c1c = (uint)*puVar7;
      puVar12 = (ushort *)((uint)*puVar7 + (int)puVar6);
      _DAT_00f22c18 = puVar6;
    }
    puVar7 = puVar12;
    if (puVar3[5] != 0) {
      _DAT_00f22c24 = (uint)puVar3[5];
      puVar7 = (ushort *)((uint)puVar3[5] + (int)puVar12);
      _DAT_00f22c20 = puVar12;
    }
    puVar6 = puVar7;
    if (puVar3[6] != 0) {
      _DAT_00f22c2c = (uint)puVar3[6];
      puVar6 = (ushort *)((uint)puVar3[6] + (int)puVar7);
      _DAT_00f22c28 = puVar7;
    }
    puVar7 = puVar6;
    if (puVar3[7] != 0) {
      _DAT_00f22c34 = (uint)puVar3[7];
      puVar7 = (ushort *)((int)puVar6 + (uint)puVar3[7]);
      _DAT_00f22c30 = puVar6;
    }
    puVar6 = puVar7;
    if (puVar3[8] != 0) {
      _DAT_00f22c3c = (uint)puVar3[8];
      puVar6 = (ushort *)((int)puVar7 + (uint)puVar3[8]);
      _DAT_00f22c38 = puVar7;
    }
    puVar7 = puVar6;
    if (puVar3[9] != 0) {
      _DAT_00f22c44 = (uint)puVar3[9];
      puVar7 = (ushort *)((int)puVar6 + (uint)puVar3[9]);
      _DAT_00f22c40 = puVar6;
    }
    puVar6 = puVar7;
    if (puVar3[10] != 0) {
      _DAT_00f22c4c = (uint)puVar3[10];
      puVar6 = (ushort *)((uint)puVar3[10] + (int)puVar7);
      _DAT_00f22c48 = puVar7;
    }
    puVar7 = puVar6;
    if (puVar3[0xb] != 0) {
      _DAT_00f22c54 = (uint)puVar3[0xb];
      puVar7 = (ushort *)((int)puVar6 + (uint)puVar3[0xb]);
      _DAT_00f22c50 = puVar6;
    }
    puVar6 = puVar7;
    if (puVar3[0xc] != 0) {
      _DAT_00f22c5c = (uint)puVar3[0xc];
      puVar6 = (ushort *)((int)puVar7 + (uint)puVar3[0xc]);
      _DAT_00f22c58 = puVar7;
    }
    puVar7 = puVar6;
    if (puVar3[0xd] != 0) {
      _DAT_00f22c64 = (uint)puVar3[0xd];
      puVar7 = (ushort *)((int)puVar6 + (uint)puVar3[0xd]);
      _DAT_00f22c60 = puVar6;
    }
    puVar6 = puVar7;
    if (puVar3[0xe] != 0) {
      DAT_00f22c6c = (uint)puVar3[0xe];
      puVar6 = (ushort *)((uint)puVar3[0xe] + (int)puVar7);
      DAT_00f22c68 = puVar7;
    }
    puVar7 = puVar6;
    if (puVar3[0xf] != 0) {
      DAT_00f22c74 = (uint)puVar3[0xf];
      puVar7 = (ushort *)((uint)puVar3[0xf] + (int)puVar6);
      DAT_00f22c70 = puVar6;
    }
    if (puVar3[0x10] != 0) {
      _DAT_00f22c7c = (uint)puVar3[0x10];
      _DAT_00f22c78 = puVar7;
    }
    if (DAT_00f3a170 == 0) {
      DAT_00f3a170 = 1;
      FUN_005702e0(&DAT_00955250,&DAT_00955250);
    }
    uVar2 = FUN_00570180(&DAT_00955250,0);
    DAT_00f23514 = (ushort *)
                   FUN_0056e030(uVar2,
                                "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxGraphicsD3D11.cpp"
                                ,0x5ed);
    if (DAT_00f23514 != (ushort *)0x0) {
      FUN_00570180(&DAT_00955250,DAT_00f23514);
      puVar7 = DAT_00f23514 + 0x200;
      puVar8 = &DAT_00f23520;
      iVar11 = 0x80;
      puVar6 = DAT_00f23514;
      do {
        if (*puVar6 != 0) {
          puVar8[-2] = puVar7;
          puVar8[-1] = (uint)*puVar6;
          puVar7 = (ushort *)((int)puVar7 + (uint)*puVar6);
        }
        if (puVar6[1] != 0) {
          *puVar8 = puVar7;
          puVar8[1] = (uint)puVar6[1];
          puVar7 = (ushort *)((int)puVar7 + (uint)puVar6[1]);
        }
        if (puVar6[2] != 0) {
          puVar8[2] = puVar7;
          puVar8[3] = (uint)puVar6[2];
          puVar7 = (ushort *)((int)puVar7 + (uint)puVar6[2]);
        }
        if (puVar6[3] != 0) {
          puVar8[4] = puVar7;
          puVar8[5] = (uint)puVar6[3];
          puVar7 = (ushort *)((int)puVar7 + (uint)puVar6[3]);
        }
        puVar8 = puVar8 + 8;
        puVar6 = puVar6 + 4;
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
      if (DAT_00f3a16c == 0) {
        DAT_00f3a16c = 1;
        FUN_005702e0(&DAT_00947928,&DAT_00947928);
      }
      uVar2 = FUN_00570180(&DAT_00947928,0);
      DAT_00f23510 = FUN_0056e030(uVar2,
                                  "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxGraphicsD3D11.cpp"
                                  ,0x605);
      if (DAT_00f23510 != 0) {
        FUN_00570180(&DAT_00947928,DAT_00f23510);
        FUN_0056e7a0(&DAT_00f22c80);
        iVar11 = FUN_0056e970(&DAT_00f22c80,DAT_00f23510,uVar2,0,0,0,0);
        if (iVar11 == 0) {
          DAT_00f203b0 = 1;
          return 1;
        }
      }
    }
    if (DAT_00f2246c != (ushort *)0x0) {
      FUN_0056e1d0(DAT_00f2246c);
      DAT_00f2246c = (ushort *)0x0;
    }
  }
  if (DAT_00f23510 != 0) {
    FUN_0056e1d0(DAT_00f23510);
    DAT_00f23510 = 0;
  }
  if (DAT_00f23514 != (ushort *)0x0) {
    FUN_0056e1d0(DAT_00f23514);
    DAT_00f23514 = (ushort *)0x0;
  }
  return 0;
}

