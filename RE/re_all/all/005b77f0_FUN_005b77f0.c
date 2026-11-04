
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005b77f0(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  ushort *puVar3;
  ushort *puVar4;
  ushort *puVar5;
  ushort *puVar6;
  int iVar7;
  
  FUN_0056da60(&DAT_00cc4814,"..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxGraphicsD3D11.cpp",
               0x6dd);
  if (DAT_00f29d50 == 1) {
    FUN_0056dac0(&DAT_00cc4814);
    return 1;
  }
  DAT_00f29d54 = (ushort *)0x0;
  if (DAT_00f3a17c == 0) {
    DAT_00f3a17c = 1;
    FUN_005702e0(&DAT_009a01d0,&DAT_009a01d0);
  }
  uVar1 = FUN_00570180(&DAT_009a01d0,0);
  DAT_00f29d54 = (ushort *)
                 FUN_0056e050(uVar1,
                              "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxGraphicsD3D11.cpp",
                              0x6f2);
  if (DAT_00f29d54 == (ushort *)0x0) {
    FUN_0056dac0(&DAT_00cc4814);
    return 0;
  }
  FUN_00570180(&DAT_009a01d0,DAT_00f29d54);
  puVar4 = DAT_00f29d54 + 0x9aa;
  puVar2 = &DAT_00f29d60;
  iVar7 = 8;
  puVar6 = DAT_00f29d54;
  do {
    if (*puVar6 != 0) {
      puVar2[-2] = puVar4;
      puVar2[-1] = (uint)*puVar6;
      puVar4 = (ushort *)((int)puVar4 + (uint)*puVar6);
    }
    if (puVar6[1] != 0) {
      *puVar2 = puVar4;
      puVar2[1] = (uint)puVar6[1];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar6[1]);
    }
    if (puVar6[2] != 0) {
      puVar2[2] = puVar4;
      puVar2[3] = (uint)puVar6[2];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar6[2]);
    }
    if (puVar6[3] != 0) {
      puVar2[4] = puVar4;
      puVar2[5] = (uint)puVar6[3];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar6[3]);
    }
    if (puVar6[4] != 0) {
      puVar2[6] = puVar4;
      puVar2[7] = (uint)puVar6[4];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar6[4]);
    }
    if (puVar6[5] != 0) {
      puVar2[8] = puVar4;
      puVar2[9] = (uint)puVar6[5];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar6[5]);
    }
    puVar2 = puVar2 + 0xc;
    puVar6 = puVar6 + 6;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  puVar2 = &DAT_00f29ee0;
  iVar7 = 0x20;
  do {
    if (*puVar6 != 0) {
      puVar2[-2] = puVar4;
      puVar2[-1] = (uint)*puVar6;
      puVar4 = (ushort *)((int)puVar4 + (uint)*puVar6);
    }
    if (puVar6[1] != 0) {
      *puVar2 = puVar4;
      puVar2[1] = (uint)puVar6[1];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar6[1]);
    }
    if (puVar6[2] != 0) {
      puVar2[2] = puVar4;
      puVar2[3] = (uint)puVar6[2];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar6[2]);
    }
    if (puVar6[3] != 0) {
      puVar2[4] = puVar4;
      puVar2[5] = (uint)puVar6[3];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar6[3]);
    }
    if (puVar6[4] != 0) {
      puVar2[6] = puVar4;
      puVar2[7] = (uint)puVar6[4];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar6[4]);
    }
    if (puVar6[5] != 0) {
      puVar2[8] = puVar4;
      puVar2[9] = (uint)puVar6[5];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar6[5]);
    }
    puVar2 = puVar2 + 0xc;
    puVar6 = puVar6 + 6;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  puVar2 = &DAT_00f2a4e0;
  iVar7 = 0xc;
  do {
    if (*puVar6 != 0) {
      puVar2[-2] = puVar4;
      puVar2[-1] = (uint)*puVar6;
      puVar4 = (ushort *)((int)puVar4 + (uint)*puVar6);
    }
    if (puVar6[1] != 0) {
      *puVar2 = puVar4;
      puVar2[1] = (uint)puVar6[1];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar6[1]);
    }
    if (puVar6[2] != 0) {
      puVar2[2] = puVar4;
      puVar2[3] = (uint)puVar6[2];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar6[2]);
    }
    if (puVar6[3] != 0) {
      puVar2[4] = puVar4;
      puVar2[5] = (uint)puVar6[3];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar6[3]);
    }
    if (puVar6[4] != 0) {
      puVar2[6] = puVar4;
      puVar2[7] = (uint)puVar6[4];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar6[4]);
    }
    if (puVar6[5] != 0) {
      puVar2[8] = puVar4;
      puVar2[9] = (uint)puVar6[5];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar6[5]);
    }
    puVar2 = puVar2 + 0xc;
    puVar6 = puVar6 + 6;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  puVar2 = &DAT_00f2a720;
  iVar7 = 0x28;
  do {
    if (*puVar6 != 0) {
      puVar2[-2] = puVar4;
      puVar2[-1] = (uint)*puVar6;
      puVar4 = (ushort *)((int)puVar4 + (uint)*puVar6);
    }
    if (puVar6[1] != 0) {
      *puVar2 = puVar4;
      puVar2[1] = (uint)puVar6[1];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar6[1]);
    }
    if (puVar6[2] != 0) {
      puVar2[2] = puVar4;
      puVar2[3] = (uint)puVar6[2];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar6[2]);
    }
    if (puVar6[3] != 0) {
      puVar2[4] = puVar4;
      puVar2[5] = (uint)puVar6[3];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar6[3]);
    }
    if (puVar6[4] != 0) {
      puVar2[6] = puVar4;
      puVar2[7] = (uint)puVar6[4];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar6[4]);
    }
    if (puVar6[5] != 0) {
      puVar2[8] = puVar4;
      puVar2[9] = (uint)puVar6[5];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar6[5]);
    }
    puVar2 = puVar2 + 0xc;
    puVar6 = puVar6 + 6;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  puVar2 = &DAT_00f2aea0;
  iVar7 = 3;
  do {
    puVar3 = puVar6;
    if (*puVar3 != 0) {
      puVar2[-2] = puVar4;
      puVar2[-1] = (uint)*puVar3;
      puVar4 = (ushort *)((int)puVar4 + (uint)*puVar3);
    }
    if (puVar3[1] != 0) {
      *puVar2 = puVar4;
      puVar2[1] = (uint)puVar3[1];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar3[1]);
    }
    if (puVar3[2] != 0) {
      puVar2[2] = puVar4;
      puVar2[3] = (uint)puVar3[2];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar3[2]);
    }
    if (puVar3[3] != 0) {
      puVar2[4] = puVar4;
      puVar2[5] = (uint)puVar3[3];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar3[3]);
    }
    if (puVar3[4] != 0) {
      puVar2[6] = puVar4;
      puVar2[7] = (uint)puVar3[4];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar3[4]);
    }
    if (puVar3[5] != 0) {
      puVar2[8] = puVar4;
      puVar2[9] = (uint)puVar3[5];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar3[5]);
    }
    puVar2 = puVar2 + 0xc;
    puVar6 = puVar3 + 6;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  puVar5 = puVar4;
  if (*puVar6 != 0) {
    _DAT_00f2af2c = (uint)*puVar6;
    puVar5 = (ushort *)((uint)*puVar6 + (int)puVar4);
    _DAT_00f2af28 = puVar4;
  }
  puVar4 = puVar5;
  if (puVar3[7] != 0) {
    _DAT_00f2af34 = (uint)puVar3[7];
    puVar4 = (ushort *)((int)puVar5 + (uint)puVar3[7]);
    _DAT_00f2af30 = puVar5;
  }
  puVar6 = puVar4;
  if (puVar3[8] != 0) {
    _DAT_00f2af3c = (uint)puVar3[8];
    puVar6 = (ushort *)((int)puVar4 + (uint)puVar3[8]);
    _DAT_00f2af38 = puVar4;
  }
  puVar4 = puVar6;
  if (puVar3[9] != 0) {
    _DAT_00f2af44 = (uint)puVar3[9];
    puVar4 = (ushort *)((int)puVar6 + (uint)puVar3[9]);
    _DAT_00f2af40 = puVar6;
  }
  puVar6 = puVar4;
  if (puVar3[10] != 0) {
    _DAT_00f2af4c = (uint)puVar3[10];
    puVar6 = (ushort *)((int)puVar4 + (uint)puVar3[10]);
    _DAT_00f2af48 = puVar4;
  }
  puVar4 = puVar6;
  if (puVar3[0xb] != 0) {
    _DAT_00f2af54 = (uint)puVar3[0xb];
    puVar4 = (ushort *)((int)puVar6 + (uint)puVar3[0xb]);
    _DAT_00f2af50 = puVar6;
  }
  puVar2 = &DAT_00f2af60;
  iVar7 = 4;
  puVar6 = puVar3 + 0xc;
  do {
    puVar3 = puVar6;
    if (*puVar3 != 0) {
      puVar2[-2] = puVar4;
      puVar2[-1] = (uint)*puVar3;
      puVar4 = (ushort *)((int)puVar4 + (uint)*puVar3);
    }
    if (puVar3[1] != 0) {
      *puVar2 = puVar4;
      puVar2[1] = (uint)puVar3[1];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar3[1]);
    }
    if (puVar3[2] != 0) {
      puVar2[2] = puVar4;
      puVar2[3] = (uint)puVar3[2];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar3[2]);
    }
    if (puVar3[3] != 0) {
      puVar2[4] = puVar4;
      puVar2[5] = (uint)puVar3[3];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar3[3]);
    }
    if (puVar3[4] != 0) {
      puVar2[6] = puVar4;
      puVar2[7] = (uint)puVar3[4];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar3[4]);
    }
    if (puVar3[5] != 0) {
      puVar2[8] = puVar4;
      puVar2[9] = (uint)puVar3[5];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar3[5]);
    }
    puVar2 = puVar2 + 0xc;
    puVar6 = puVar3 + 6;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  puVar5 = puVar4;
  if (*puVar6 != 0) {
    _DAT_00f2b01c = (uint)*puVar6;
    puVar5 = (ushort *)((uint)*puVar6 + (int)puVar4);
    _DAT_00f2b018 = puVar4;
  }
  puVar4 = puVar5;
  if (puVar3[7] != 0) {
    _DAT_00f2b024 = (uint)puVar3[7];
    puVar4 = (ushort *)((int)puVar5 + (uint)puVar3[7]);
    _DAT_00f2b020 = puVar5;
  }
  puVar6 = puVar4;
  if (puVar3[8] != 0) {
    _DAT_00f2b02c = (uint)puVar3[8];
    puVar6 = (ushort *)((int)puVar4 + (uint)puVar3[8]);
    _DAT_00f2b028 = puVar4;
  }
  puVar4 = puVar6;
  if (puVar3[9] != 0) {
    _DAT_00f2b034 = (uint)puVar3[9];
    puVar4 = (ushort *)((int)puVar6 + (uint)puVar3[9]);
    _DAT_00f2b030 = puVar6;
  }
  puVar6 = puVar4;
  if (puVar3[10] != 0) {
    _DAT_00f2b03c = (uint)puVar3[10];
    puVar6 = (ushort *)((int)puVar4 + (uint)puVar3[10]);
    _DAT_00f2b038 = puVar4;
  }
  puVar4 = puVar6;
  if (puVar3[0xb] != 0) {
    _DAT_00f2b044 = (uint)puVar3[0xb];
    puVar4 = (ushort *)((int)puVar6 + (uint)puVar3[0xb]);
    _DAT_00f2b040 = puVar6;
  }
  puVar3 = puVar3 + 0xc;
  puVar2 = &DAT_00f2b050;
  iVar7 = 4;
  do {
    if (*puVar3 != 0) {
      puVar2[-2] = puVar4;
      puVar2[-1] = (uint)*puVar3;
      puVar4 = (ushort *)((int)puVar4 + (uint)*puVar3);
    }
    if (puVar3[1] != 0) {
      *puVar2 = puVar4;
      puVar2[1] = (uint)puVar3[1];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar3[1]);
    }
    if (puVar3[2] != 0) {
      puVar2[2] = puVar4;
      puVar2[3] = (uint)puVar3[2];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar3[2]);
    }
    if (puVar3[3] != 0) {
      puVar2[4] = puVar4;
      puVar2[5] = (uint)puVar3[3];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar3[3]);
    }
    if (puVar3[4] != 0) {
      puVar2[6] = puVar4;
      puVar2[7] = (uint)puVar3[4];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar3[4]);
    }
    if (puVar3[5] != 0) {
      puVar2[8] = puVar4;
      puVar2[9] = (uint)puVar3[5];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar3[5]);
    }
    puVar2 = puVar2 + 0xc;
    puVar3 = puVar3 + 6;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  puVar2 = &DAT_00f2b110;
  iVar7 = 0xa0;
  do {
    if (*puVar3 != 0) {
      puVar2[-2] = puVar4;
      puVar2[-1] = (uint)*puVar3;
      puVar4 = (ushort *)((int)puVar4 + (uint)*puVar3);
    }
    if (puVar3[1] != 0) {
      *puVar2 = puVar4;
      puVar2[1] = (uint)puVar3[1];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar3[1]);
    }
    if (puVar3[2] != 0) {
      puVar2[2] = puVar4;
      puVar2[3] = (uint)puVar3[2];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar3[2]);
    }
    if (puVar3[3] != 0) {
      puVar2[4] = puVar4;
      puVar2[5] = (uint)puVar3[3];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar3[3]);
    }
    if (puVar3[4] != 0) {
      puVar2[6] = puVar4;
      puVar2[7] = (uint)puVar3[4];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar3[4]);
    }
    if (puVar3[5] != 0) {
      puVar2[8] = puVar4;
      puVar2[9] = (uint)puVar3[5];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar3[5]);
    }
    puVar2 = puVar2 + 0xc;
    puVar3 = puVar3 + 6;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  puVar2 = &DAT_00f2cf10;
  iVar7 = 4;
  do {
    puVar6 = puVar3;
    if (*puVar6 != 0) {
      puVar2[-2] = puVar4;
      puVar2[-1] = (uint)*puVar6;
      puVar4 = (ushort *)((int)puVar4 + (uint)*puVar6);
    }
    if (puVar6[1] != 0) {
      *puVar2 = puVar4;
      puVar2[1] = (uint)puVar6[1];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar6[1]);
    }
    if (puVar6[2] != 0) {
      puVar2[2] = puVar4;
      puVar2[3] = (uint)puVar6[2];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar6[2]);
    }
    if (puVar6[3] != 0) {
      puVar2[4] = puVar4;
      puVar2[5] = (uint)puVar6[3];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar6[3]);
    }
    if (puVar6[4] != 0) {
      puVar2[6] = puVar4;
      puVar2[7] = (uint)puVar6[4];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar6[4]);
    }
    if (puVar6[5] != 0) {
      puVar2[8] = puVar4;
      puVar2[9] = (uint)puVar6[5];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar6[5]);
    }
    puVar2 = puVar2 + 0xc;
    puVar3 = puVar6 + 6;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  puVar5 = puVar4;
  if (*puVar3 != 0) {
    _DAT_00f2cfcc = (uint)*puVar3;
    puVar5 = (ushort *)((uint)*puVar3 + (int)puVar4);
    _DAT_00f2cfc8 = puVar4;
  }
  puVar4 = puVar5;
  if (puVar6[7] != 0) {
    _DAT_00f2cfd4 = (uint)puVar6[7];
    puVar4 = (ushort *)((int)puVar5 + (uint)puVar6[7]);
    _DAT_00f2cfd0 = puVar5;
  }
  puVar3 = puVar4;
  if (puVar6[8] != 0) {
    _DAT_00f2cfdc = (uint)puVar6[8];
    puVar3 = (ushort *)((uint)puVar6[8] + (int)puVar4);
    _DAT_00f2cfd8 = puVar4;
  }
  puVar4 = puVar3;
  if (puVar6[9] != 0) {
    _DAT_00f2cfe4 = (uint)puVar6[9];
    puVar4 = (ushort *)((int)puVar3 + (uint)puVar6[9]);
    _DAT_00f2cfe0 = puVar3;
  }
  puVar3 = puVar4;
  if (puVar6[10] != 0) {
    _DAT_00f2cfec = (uint)puVar6[10];
    puVar3 = (ushort *)((int)puVar4 + (uint)puVar6[10]);
    _DAT_00f2cfe8 = puVar4;
  }
  puVar4 = puVar3;
  if (puVar6[0xb] != 0) {
    _DAT_00f2cff4 = (uint)puVar6[0xb];
    puVar4 = (ushort *)((int)puVar3 + (uint)puVar6[0xb]);
    _DAT_00f2cff0 = puVar3;
  }
  puVar3 = puVar4;
  if (puVar6[0xc] != 0) {
    _DAT_00f2cffc = (uint)puVar6[0xc];
    puVar3 = (ushort *)((int)puVar4 + (uint)puVar6[0xc]);
    _DAT_00f2cff8 = puVar4;
  }
  puVar4 = puVar3;
  if (puVar6[0xd] != 0) {
    _DAT_00f2d004 = (uint)puVar6[0xd];
    puVar4 = (ushort *)((int)puVar3 + (uint)puVar6[0xd]);
    _DAT_00f2d000 = puVar3;
  }
  puVar3 = puVar4;
  if (puVar6[0xe] != 0) {
    _DAT_00f2d00c = (uint)puVar6[0xe];
    puVar3 = (ushort *)((int)puVar4 + (uint)puVar6[0xe]);
    _DAT_00f2d008 = puVar4;
  }
  puVar4 = puVar3;
  if (puVar6[0xf] != 0) {
    _DAT_00f2d014 = (uint)puVar6[0xf];
    puVar4 = (ushort *)((int)puVar3 + (uint)puVar6[0xf]);
    _DAT_00f2d010 = puVar3;
  }
  puVar3 = puVar4;
  if (puVar6[0x10] != 0) {
    _DAT_00f2d01c = (uint)puVar6[0x10];
    puVar3 = (ushort *)((uint)puVar6[0x10] + (int)puVar4);
    _DAT_00f2d018 = puVar4;
  }
  puVar4 = puVar3;
  if (puVar6[0x11] != 0) {
    _DAT_00f2d024 = (uint)puVar6[0x11];
    puVar4 = (ushort *)((int)puVar3 + (uint)puVar6[0x11]);
    _DAT_00f2d020 = puVar3;
  }
  puVar3 = puVar4;
  if (puVar6[0x12] != 0) {
    _DAT_00f2d02c = (uint)puVar6[0x12];
    puVar3 = (ushort *)((int)puVar4 + (uint)puVar6[0x12]);
    _DAT_00f2d028 = puVar4;
  }
  puVar4 = puVar3;
  if (puVar6[0x13] != 0) {
    _DAT_00f2d034 = (uint)puVar6[0x13];
    puVar4 = (ushort *)((int)puVar3 + (uint)puVar6[0x13]);
    _DAT_00f2d030 = puVar3;
  }
  puVar3 = puVar4;
  if (puVar6[0x14] != 0) {
    _DAT_00f2d03c = (uint)puVar6[0x14];
    puVar3 = (ushort *)((int)puVar4 + (uint)puVar6[0x14]);
    _DAT_00f2d038 = puVar4;
  }
  puVar4 = puVar3;
  if (puVar6[0x15] != 0) {
    _DAT_00f2d044 = (uint)puVar6[0x15];
    puVar4 = (ushort *)((int)puVar3 + (uint)puVar6[0x15]);
    _DAT_00f2d040 = puVar3;
  }
  puVar3 = puVar4;
  if (puVar6[0x16] != 0) {
    _DAT_00f2d04c = (uint)puVar6[0x16];
    puVar3 = (ushort *)((int)puVar4 + (uint)puVar6[0x16]);
    _DAT_00f2d048 = puVar4;
  }
  puVar4 = puVar3;
  if (puVar6[0x17] != 0) {
    _DAT_00f2d054 = (uint)puVar6[0x17];
    puVar4 = (ushort *)((int)puVar3 + (uint)puVar6[0x17]);
    _DAT_00f2d050 = puVar3;
  }
  puVar3 = puVar4;
  if (puVar6[0x18] != 0) {
    _DAT_00f2d05c = (uint)puVar6[0x18];
    puVar3 = (ushort *)((int)puVar4 + (uint)puVar6[0x18]);
    _DAT_00f2d058 = puVar4;
  }
  puVar4 = puVar3;
  if (puVar6[0x19] != 0) {
    _DAT_00f2d064 = (uint)puVar6[0x19];
    puVar4 = (ushort *)((int)puVar3 + (uint)puVar6[0x19]);
    _DAT_00f2d060 = puVar3;
  }
  puVar6 = puVar6 + 0x1a;
  puVar2 = &DAT_00f2d070;
  iVar7 = 0x40;
  do {
    if (*puVar6 != 0) {
      puVar2[-2] = puVar4;
      puVar2[-1] = (uint)*puVar6;
      puVar4 = (ushort *)((int)puVar4 + (uint)*puVar6);
    }
    if (puVar6[1] != 0) {
      *puVar2 = puVar4;
      puVar2[1] = (uint)puVar6[1];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar6[1]);
    }
    if (puVar6[2] != 0) {
      puVar2[2] = puVar4;
      puVar2[3] = (uint)puVar6[2];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar6[2]);
    }
    if (puVar6[3] != 0) {
      puVar2[4] = puVar4;
      puVar2[5] = (uint)puVar6[3];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar6[3]);
    }
    if (puVar6[4] != 0) {
      puVar2[6] = puVar4;
      puVar2[7] = (uint)puVar6[4];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar6[4]);
    }
    puVar2 = puVar2 + 10;
    puVar6 = puVar6 + 5;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  puVar2 = &DAT_00f2da70;
  iVar7 = 0x14;
  do {
    puVar3 = puVar6;
    if (*puVar3 != 0) {
      puVar2[-2] = puVar4;
      puVar2[-1] = (uint)*puVar3;
      puVar4 = (ushort *)((int)puVar4 + (uint)*puVar3);
    }
    if (puVar3[1] != 0) {
      *puVar2 = puVar4;
      puVar2[1] = (uint)puVar3[1];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar3[1]);
    }
    if (puVar3[2] != 0) {
      puVar2[2] = puVar4;
      puVar2[3] = (uint)puVar3[2];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar3[2]);
    }
    if (puVar3[3] != 0) {
      puVar2[4] = puVar4;
      puVar2[5] = (uint)puVar3[3];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar3[3]);
    }
    if (puVar3[4] != 0) {
      puVar2[6] = puVar4;
      puVar2[7] = (uint)puVar3[4];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar3[4]);
    }
    if (puVar3[5] != 0) {
      puVar2[8] = puVar4;
      puVar2[9] = (uint)puVar3[5];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar3[5]);
    }
    puVar2 = puVar2 + 0xc;
    iVar7 = iVar7 + -1;
    puVar6 = puVar3 + 6;
  } while (iVar7 != 0);
  puVar3 = puVar3 + 8;
  puVar2 = &DAT_00f2de30;
  iVar7 = 0x50;
  do {
    if (puVar3[-2] != 0) {
      puVar2[-2] = puVar4;
      puVar2[-1] = (uint)puVar3[-2];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar3[-2]);
    }
    if (puVar3[-1] != 0) {
      *puVar2 = puVar4;
      puVar2[1] = (uint)puVar3[-1];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar3[-1]);
    }
    if (*puVar3 != 0) {
      puVar2[2] = puVar4;
      puVar2[3] = (uint)*puVar3;
      puVar4 = (ushort *)((int)puVar4 + (uint)*puVar3);
    }
    if (puVar3[1] != 0) {
      puVar2[4] = puVar4;
      puVar2[5] = (uint)puVar3[1];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar3[1]);
    }
    if (puVar3[2] != 0) {
      puVar2[6] = puVar4;
      puVar2[7] = (uint)puVar3[2];
      puVar4 = (ushort *)((int)puVar4 + (uint)puVar3[2]);
    }
    puVar2 = puVar2 + 10;
    puVar3 = puVar3 + 5;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  DAT_00f29d50 = 1;
  FUN_0056dac0(&DAT_00cc4814);
  return 1;
}

