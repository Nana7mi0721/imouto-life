
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005b7340(void)

{
  undefined4 uVar1;
  ushort *puVar2;
  undefined4 *puVar3;
  ushort *puVar4;
  ushort *puVar5;
  ushort *puVar6;
  int iVar7;
  
  if (DAT_00f24518 != 1) {
    FUN_0056da60(&DAT_00cc4814,"..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxGraphicsD3D11.cpp"
                 ,0x66f);
    if (DAT_00f24518 == 1) {
      FUN_0056dac0(&DAT_00cc4814);
      return 1;
    }
    DAT_00f2451c = (ushort *)0x0;
    if (DAT_00f3a178 == 0) {
      DAT_00f3a178 = 1;
      FUN_005702e0(&DAT_00966100,&DAT_00966100);
    }
    uVar1 = FUN_00570180(&DAT_00966100,0);
    DAT_00f2451c = (ushort *)
                   FUN_0056e050(uVar1,
                                "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxGraphicsD3D11.cpp"
                                ,0x684);
    if (DAT_00f2451c == (ushort *)0x0) {
      FUN_0056dac0(&DAT_00cc4814);
      return 0;
    }
    FUN_00570180(&DAT_00966100,DAT_00f2451c);
    puVar6 = DAT_00f2451c + 0xb06;
    puVar5 = puVar6;
    if (*DAT_00f2451c != 0) {
      _DAT_00f24524 = (uint)*DAT_00f2451c;
      puVar5 = (ushort *)((int)puVar6 + (uint)*DAT_00f2451c);
      _DAT_00f24520 = puVar6;
    }
    puVar6 = puVar5;
    if (DAT_00f2451c[1] != 0) {
      _DAT_00f2452c = (uint)DAT_00f2451c[1];
      puVar6 = (ushort *)((int)puVar5 + (uint)DAT_00f2451c[1]);
      _DAT_00f24528 = puVar5;
    }
    puVar5 = puVar6;
    if (DAT_00f2451c[2] != 0) {
      _DAT_00f24534 = (uint)DAT_00f2451c[2];
      puVar5 = (ushort *)((int)puVar6 + (uint)DAT_00f2451c[2]);
      _DAT_00f24530 = puVar6;
    }
    puVar6 = puVar5;
    if (DAT_00f2451c[3] != 0) {
      _DAT_00f2453c = (uint)DAT_00f2451c[3];
      puVar6 = (ushort *)((int)puVar5 + (uint)DAT_00f2451c[3]);
      _DAT_00f24538 = puVar5;
    }
    puVar5 = puVar6;
    if (DAT_00f2451c[4] != 0) {
      _DAT_00f24544 = (uint)DAT_00f2451c[4];
      puVar5 = (ushort *)((int)puVar6 + (uint)DAT_00f2451c[4]);
      _DAT_00f24540 = puVar6;
    }
    puVar6 = puVar5;
    if (DAT_00f2451c[5] != 0) {
      _DAT_00f2454c = (uint)DAT_00f2451c[5];
      puVar6 = (ushort *)((int)puVar5 + (uint)DAT_00f2451c[5]);
      _DAT_00f24548 = puVar5;
    }
    puVar5 = puVar6;
    if (DAT_00f2451c[6] != 0) {
      _DAT_00f24554 = (uint)DAT_00f2451c[6];
      puVar5 = (ushort *)((int)puVar6 + (uint)DAT_00f2451c[6]);
      _DAT_00f24550 = puVar6;
    }
    puVar6 = puVar5;
    if (DAT_00f2451c[7] != 0) {
      _DAT_00f2455c = (uint)DAT_00f2451c[7];
      puVar6 = (ushort *)((int)puVar5 + (uint)DAT_00f2451c[7]);
      _DAT_00f24558 = puVar5;
    }
    puVar3 = &DAT_00f24568;
    iVar7 = 0x188;
    puVar5 = DAT_00f2451c + 8;
    do {
      puVar2 = puVar5;
      if (*puVar2 != 0) {
        puVar3[-2] = puVar6;
        puVar3[-1] = (uint)*puVar2;
        puVar6 = (ushort *)((int)puVar6 + (uint)*puVar2);
      }
      if (puVar2[1] != 0) {
        *puVar3 = puVar6;
        puVar3[1] = (uint)puVar2[1];
        puVar6 = (ushort *)((int)puVar6 + (uint)puVar2[1]);
      }
      if (puVar2[2] != 0) {
        puVar3[2] = puVar6;
        puVar3[3] = (uint)puVar2[2];
        puVar6 = (ushort *)((int)puVar6 + (uint)puVar2[2]);
      }
      if (puVar2[3] != 0) {
        puVar3[4] = puVar6;
        puVar3[5] = (uint)puVar2[3];
        puVar6 = (ushort *)((int)puVar6 + (uint)puVar2[3]);
      }
      if (puVar2[4] != 0) {
        puVar3[6] = puVar6;
        puVar3[7] = (uint)puVar2[4];
        puVar6 = (ushort *)((int)puVar6 + (uint)puVar2[4]);
      }
      if (puVar2[5] != 0) {
        puVar3[8] = puVar6;
        puVar3[9] = (uint)puVar2[5];
        puVar6 = (ushort *)((int)puVar6 + (uint)puVar2[5]);
      }
      puVar3 = puVar3 + 0xc;
      puVar5 = puVar2 + 6;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    puVar4 = puVar6;
    if (*puVar5 != 0) {
      _DAT_00f28ee4 = (uint)*puVar5;
      puVar4 = (ushort *)((uint)*puVar5 + (int)puVar6);
      _DAT_00f28ee0 = puVar6;
    }
    puVar6 = puVar4;
    if (puVar2[7] != 0) {
      _DAT_00f28eec = (uint)puVar2[7];
      puVar6 = (ushort *)((int)puVar4 + (uint)puVar2[7]);
      _DAT_00f28ee8 = puVar4;
    }
    puVar5 = puVar6;
    if (puVar2[8] != 0) {
      _DAT_00f28ef4 = (uint)puVar2[8];
      puVar5 = (ushort *)((uint)puVar2[8] + (int)puVar6);
      _DAT_00f28ef0 = puVar6;
    }
    puVar6 = puVar5;
    if (puVar2[9] != 0) {
      _DAT_00f28efc = (uint)puVar2[9];
      puVar6 = (ushort *)((int)puVar5 + (uint)puVar2[9]);
      _DAT_00f28ef8 = puVar5;
    }
    puVar5 = puVar6;
    if (puVar2[10] != 0) {
      _DAT_00f28f04 = (uint)puVar2[10];
      puVar5 = (ushort *)((int)puVar6 + (uint)puVar2[10]);
      _DAT_00f28f00 = puVar6;
    }
    puVar6 = puVar5;
    if (puVar2[0xb] != 0) {
      _DAT_00f28f0c = (uint)puVar2[0xb];
      puVar6 = (ushort *)((int)puVar5 + (uint)puVar2[0xb]);
      _DAT_00f28f08 = puVar5;
    }
    puVar3 = &DAT_00f28f18;
    iVar7 = 0x20;
    puVar5 = puVar2 + 0xc;
    do {
      puVar2 = puVar5;
      if (*puVar2 != 0) {
        puVar3[-2] = puVar6;
        puVar3[-1] = (uint)*puVar2;
        puVar6 = (ushort *)((int)puVar6 + (uint)*puVar2);
      }
      if (puVar2[1] != 0) {
        *puVar3 = puVar6;
        puVar3[1] = (uint)puVar2[1];
        puVar6 = (ushort *)((int)puVar6 + (uint)puVar2[1]);
      }
      if (puVar2[2] != 0) {
        puVar3[2] = puVar6;
        puVar3[3] = (uint)puVar2[2];
        puVar6 = (ushort *)((int)puVar6 + (uint)puVar2[2]);
      }
      if (puVar2[3] != 0) {
        puVar3[4] = puVar6;
        puVar3[5] = (uint)puVar2[3];
        puVar6 = (ushort *)((int)puVar6 + (uint)puVar2[3]);
      }
      if (puVar2[4] != 0) {
        puVar3[6] = puVar6;
        puVar3[7] = (uint)puVar2[4];
        puVar6 = (ushort *)((int)puVar6 + (uint)puVar2[4]);
      }
      puVar3 = puVar3 + 10;
      puVar5 = puVar2 + 5;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    puVar4 = puVar6;
    if (*puVar5 != 0) {
      _DAT_00f29414 = (uint)*puVar5;
      puVar4 = (ushort *)((uint)*puVar5 + (int)puVar6);
      _DAT_00f29410 = puVar6;
    }
    puVar6 = puVar4;
    if (puVar2[6] != 0) {
      _DAT_00f2941c = (uint)puVar2[6];
      puVar6 = (ushort *)((int)puVar4 + (uint)puVar2[6]);
      _DAT_00f29418 = puVar4;
    }
    puVar3 = &DAT_00f29428;
    iVar7 = 7;
    puVar5 = puVar2 + 7;
    do {
      puVar2 = puVar5;
      if (*puVar2 != 0) {
        puVar3[-2] = puVar6;
        puVar3[-1] = (uint)*puVar2;
        puVar6 = (ushort *)((int)puVar6 + (uint)*puVar2);
      }
      if (puVar2[1] != 0) {
        *puVar3 = puVar6;
        puVar3[1] = (uint)puVar2[1];
        puVar6 = (ushort *)((int)puVar6 + (uint)puVar2[1]);
      }
      puVar3 = puVar3 + 4;
      iVar7 = iVar7 + -1;
      puVar5 = puVar2 + 2;
    } while (iVar7 != 0);
    puVar2 = puVar2 + 4;
    puVar3 = &DAT_00f29498;
    iVar7 = 0x38;
    do {
      if (puVar2[-2] != 0) {
        puVar3[-2] = puVar6;
        puVar3[-1] = (uint)puVar2[-2];
        puVar6 = (ushort *)((int)puVar6 + (uint)puVar2[-2]);
      }
      if (puVar2[-1] != 0) {
        *puVar3 = puVar6;
        puVar3[1] = (uint)puVar2[-1];
        puVar6 = (ushort *)((int)puVar6 + (uint)puVar2[-1]);
      }
      if (*puVar2 != 0) {
        puVar3[2] = puVar6;
        puVar3[3] = (uint)*puVar2;
        puVar6 = (ushort *)((int)puVar6 + (uint)*puVar2);
      }
      if (puVar2[1] != 0) {
        puVar3[4] = puVar6;
        puVar3[5] = (uint)puVar2[1];
        puVar6 = (ushort *)((int)puVar6 + (uint)puVar2[1]);
      }
      if (puVar2[2] != 0) {
        puVar3[6] = puVar6;
        puVar3[7] = (uint)puVar2[2];
        puVar6 = (ushort *)((int)puVar6 + (uint)puVar2[2]);
      }
      puVar3 = puVar3 + 10;
      puVar2 = puVar2 + 5;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    DAT_00f24518 = 1;
    FUN_0056dac0(&DAT_00cc4814);
  }
  return 1;
}

