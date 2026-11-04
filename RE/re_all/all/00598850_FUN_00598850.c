
/* WARNING: Removing unreachable block (ram,0x0059a57b) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00598850(void)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  HMONITOR hMonitor;
  int iVar4;
  undefined *puVar5;
  undefined4 uVar6;
  uint uVar7;
  char *pcVar8;
  uint uVar9;
  longlong lVar10;
  undefined8 uVar11;
  char *pcStack_4f4;
  int iStack_4f0;
  int iStack_4ec;
  undefined8 uStack_4e8;
  int iStack_4dc;
  int iStack_4d8;
  int iStack_4d4;
  uint uStack_4cc;
  int iStack_4c8;
  int iStack_4c4;
  int aiStack_4c0 [3];
  uint uStack_4b4;
  tagMONITORINFO tStack_4a0;
  undefined1 auStack_458 [512];
  undefined1 auStack_258 [596];
  
  pcVar8 = (char *)0x0;
  iVar3 = FUN_005d35f0();
  if (iVar3 == 0) {
    return 0xffffffff;
  }
  FUN_005d3630();
  DAT_00e79688 = 0;
  iVar3 = thunk_FUN_00568c60();
  if (iVar3 < 200) {
    DAT_00a37d84 = 0;
    DAT_00a37d88 = 0;
  }
  iVar3 = FUN_005d6120();
  if (iVar3 < 0) {
    DAT_00a37e70 = 0x20;
    FUN_005811a0(1);
    iVar3 = FUN_005d6120();
    if (iVar3 < 0) {
      FUN_005173e0(800,600);
      iVar3 = FUN_005d6120();
      if (iVar3 < 0) {
        FUN_005173e0(0x400,0x300);
        iVar3 = FUN_005d6120();
        if (iVar3 < 0) {
          return 0xffffffff;
        }
      }
    }
  }
  FUN_005d4bf0();
  DAT_00e8062c = 0;
  DAT_00e80628 = 0;
  DAT_00e80624 = 0;
  DAT_00e80614 = 0;
  DAT_00e80618 = 0;
  DAT_00e80630 = 0;
  DAT_00e80634 = 0;
  FUN_005d36a0(0,0,0,&DAT_00ddb5b4);
  FUN_0056bb10(&DAT_007d4974);
  iVar3 = FUN_0050e7d0();
  if (iVar3 == 0) {
    hMonitor = (HMONITOR)FUN_005d34a0(-(uint)(DAT_00a37eec != 0) & _DAT_00a37ef0);
    FUN_0056d380(&tStack_4a0,0,0x48);
    tStack_4a0.cbSize = 0x48;
    GetMonitorInfoA(hMonitor,&tStack_4a0);
    _DAT_00a37eac = tStack_4a0.rcMonitor.left;
    _DAT_00a37eb0 = tStack_4a0.rcMonitor.top;
    _DAT_00a37eb4 = tStack_4a0.rcMonitor.right;
    _DAT_00a37eb8 = tStack_4a0.rcMonitor.bottom;
  }
  FUN_005d3680(&DAT_00ddb380);
  DAT_00ddb4b4 = DAT_00ddb414;
  DAT_00a37dcc = 1;
  DAT_00a37dd0 = 0;
  DAT_00a37dd4 = 1;
  DAT_00a37da8 = DAT_00ddb470;
  if (8 < DAT_00ddb470) {
    DAT_00a37da8 = 8;
  }
  DAT_00ddb4b8 = DAT_00ddb3a0 >> 10 & 1;
  if (DAT_00ddb370 == 0) {
    uVar7 = DAT_00ddb444 & 0xffff;
    DAT_00ddb5f0 = (uint)(0x1ff < uVar7);
    uVar9 = DAT_00ddb44c & 0xffff;
    DAT_00ddb5f4 = (uint)(0x1ff < uVar9);
    DAT_00ddb5f8 = (uint)(0x2ff < uVar7);
    DAT_00ddb5fc = (uint)(0x2ff < uVar9);
    if ((0x2ff >= uVar7) || (0x2ff >= uVar9)) goto LAB_00598a71;
  }
  else {
    DAT_00ddb5f0 = 0;
    DAT_00ddb5f4 = 0;
LAB_00598a71:
    DAT_00ddb5fc = 0;
    DAT_00ddb5f8 = 0;
  }
  DAT_00a37d8c = DAT_00ddb3a0 >> 0xb & 1;
  DAT_00a37dac = DAT_00ddb3bc >> 8 & 1;
  DAT_00a37db0 = DAT_00ddb3bc >> 1 & 1;
  DAT_00a37da4 = DAT_00ddb3bc >> 5 & 1;
  if (DAT_00ddb3d8 == 0) {
    DAT_00ddb3d8 = 0x100;
  }
  if (DAT_00ddb3dc == 0) {
    DAT_00ddb3dc = 0x100;
  }
  DAT_00a37db4 = DAT_00ddb3d8;
  if (DAT_00ddb3dc <= DAT_00ddb3d8) {
    DAT_00a37db4 = DAT_00ddb3dc;
  }
  DAT_00a37dc4 = DAT_00ddb438;
  DAT_00a37dc0 = DAT_00ddb434;
  DAT_00e804f8 = 0xff;
  DAT_00e804fc = 0xff;
  DAT_00e39a00 = 1;
  DAT_00a37db8 = DAT_00ddb3d8;
  DAT_00a37dbc = DAT_00ddb3dc;
  DAT_00ddb4bc = DAT_00a37d8c;
  FUN_005d3400(0,0,auStack_458);
  FUN_0056bc00("Driver:%s  Description:%s",auStack_458,auStack_258);
  uVar7 = -(uint)(DAT_00a37eec != 0) & _DAT_00a37ef0;
  FUN_005d2730(DAT_00ddb5b4,aiStack_4c0);
  DAT_00ddb4d0 = aiStack_4c0[0];
  if (aiStack_4c0[0] == 0x16) {
    pcVar8 = "D3DFMT_X8R8G8B8";
  }
  else if (aiStack_4c0[0] == 0x17) {
    pcVar8 = "D3DFMT_R5G6B5";
  }
  else if (aiStack_4c0[0] == 0x18) {
    pcVar8 = "D3DFMT_X1R5G5B5";
  }
  else {
    FUN_0056bc00(&DAT_007fbc70,aiStack_4c0[0]);
  }
  FUN_0056bc00(&DAT_007fbc20,pcVar8);
  DAT_00ddb598 = 0x50;
  FUN_0056bc00(&DAT_007fbbec,"D3DFMT_D16");
  iVar3 = DAT_00ddb4d0;
  iVar4 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,2,1,0x4d);
  if ((iVar4 == 0) && (iVar3 = FUN_005d3450(uVar7,1,iVar3,iVar3,0x4d), iVar3 == 0)) {
    DAT_00ddb59c = 0x4d;
    pcStack_4f4 = "D3DFMT_D24X8";
  }
  else {
    iVar3 = DAT_00ddb4d0;
    iVar4 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,2,1,0x47);
    if ((iVar4 == 0) && (iVar3 = FUN_005d3450(uVar7,1,iVar3,iVar3,0x47), iVar3 == 0)) {
      DAT_00ddb59c = 0x47;
      pcStack_4f4 = "D3DFMT_D32";
    }
    else {
      DAT_00ddb59c = 0x50;
      pcStack_4f4 = "D3DFMT_D16";
    }
  }
  FUN_0056bc00(&DAT_007fbba8,pcStack_4f4);
  iVar3 = DAT_00ddb4d0;
  iVar4 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,2,1,0x47);
  if ((iVar4 == 0) && (iVar3 = FUN_005d3450(uVar7,1,iVar3,iVar3,0x47), iVar3 == 0)) {
    DAT_00ddb5a0 = 0x47;
    pcVar8 = "D3DFMT_D32";
  }
  else {
    iVar3 = DAT_00ddb4d0;
    iVar4 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,2,1,0x4d);
    if ((iVar4 == 0) && (iVar3 = FUN_005d3450(uVar7,1,iVar3,iVar3,0x4d), iVar3 == 0)) {
      DAT_00ddb5a0 = 0x4d;
      pcVar8 = "D3DFMT_D24X8";
    }
    else {
      iVar3 = FUN_00598810(uVar7,DAT_00ddb4d0);
      if (iVar3 == 0) {
        DAT_00ddb5a0 = 0x50;
        pcStack_4f4 = "D3DFMT_D16";
      }
      pcVar8 = pcStack_4f4;
    }
  }
  FUN_0056bc00(&DAT_007fbb80,pcVar8);
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x17);
  if (iVar3 == 0) {
    DAT_00ddb4ec = 0x17;
    pcVar8 = "D3DFMT_R5G6B5";
  }
  else {
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x18);
    if (iVar3 != 0) {
      FUN_0056bb10(&DAT_007fa220);
      return 0xffffffff;
    }
    DAT_00ddb4ec = 0x18;
    pcVar8 = "D3DFMT_X1R5G5B5";
  }
  FUN_0056bc00(&DAT_007fbb5c,pcVar8);
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x16);
  if (iVar3 == 0) {
    DAT_00ddb4f0 = 0x16;
    pcVar8 = "D3DFMT_X8R8G8B8";
  }
  else {
    DAT_00ddb4f0 = DAT_00ddb4ec;
  }
  FUN_0056bc00(&DAT_007fbb38,pcVar8);
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x1a);
  if (iVar3 == 0) {
    DAT_00ddb4f4 = 0x1a;
    pcVar8 = "D3DFMT_A4R4G4B4";
  }
  else {
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x15);
    if (iVar3 != 0) {
      FUN_0056bb10(&DAT_007fa268);
      return 0xffffffff;
    }
    DAT_00ddb4f4 = 0x15;
    pcVar8 = "D3DFMT_A8R8G8B8";
  }
  FUN_0056bc00(&DAT_007fbae8,pcVar8);
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x15);
  if (iVar3 == 0) {
    DAT_00ddb4f8 = 0x15;
    pcVar8 = "D3DFMT_A8R8G8B8";
  }
  else {
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x1a);
    if (iVar3 != 0) {
      FUN_0056bb10(&DAT_007fa2b8);
      return 0xffffffff;
    }
    DAT_00ddb4f8 = 0x1a;
    pcVar8 = "D3DFMT_A4R4G4B4";
  }
  FUN_0056bc00(&DAT_007fbab8,pcVar8);
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x19);
  if (iVar3 == 0) {
    DAT_00ddb4fc = 0x19;
    pcVar8 = "D3DFMT_A1R5G5B5";
  }
  else {
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x15);
    if (iVar3 == 0) {
      DAT_00ddb4fc = 0x15;
      pcVar8 = "D3DFMT_A8R8G8B8";
    }
    else {
      iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x1a);
      if (iVar3 != 0) {
        FUN_0056bb10(&DAT_007fa308);
        return 0xffffffff;
      }
      DAT_00ddb4fc = 0x1a;
      pcVar8 = "D3DFMT_A4R4G4B4";
    }
  }
  FUN_0056bc00(&DAT_007fba74,pcVar8);
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x15);
  if (iVar3 == 0) {
    DAT_00ddb500 = 0x15;
    pcVar8 = "D3DFMT_A8R8G8B8";
  }
  else {
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x19);
    if (iVar3 == 0) {
      DAT_00ddb500 = 0x19;
      pcVar8 = "D3DFMT_A1R5G5B5";
    }
    else {
      iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x1a);
      if (iVar3 != 0) {
        FUN_0056bb10(&DAT_007fa360);
        return 0xffffffff;
      }
      DAT_00ddb500 = 0x1a;
      pcVar8 = "D3DFMT_A4R4G4B4";
    }
  }
  FUN_0056bc00(&DAT_007fba40,pcVar8);
  if (DAT_00a37e70 == 0x10) {
    _DAT_00ddb4d8 = DAT_00ddb4ec;
    _DAT_00ddb4e0 = DAT_00ddb4f4;
    _DAT_00ddb4e4 = DAT_00ddb4fc;
  }
  else {
    _DAT_00ddb4d8 = DAT_00ddb4f0;
    _DAT_00ddb4e0 = DAT_00ddb4f8;
    _DAT_00ddb4e4 = DAT_00ddb500;
  }
  _DAT_00ddb4d4 = _DAT_00ddb4d8;
  _DAT_00ddb4dc = _DAT_00ddb4e0;
  _DAT_00ddb4e8 = _DAT_00ddb4e4;
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x31545844);
  if (iVar3 == 0) {
    _DAT_00ddb504 = 0x31545844;
    puVar5 = &DAT_007fba2c;
  }
  else {
    _DAT_00ddb504 = DAT_00ddb4fc;
    puVar5 = &DAT_007fba20;
  }
  FUN_0056bc00(&DAT_007fb9fc,puVar5);
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x32545844);
  if (iVar3 == 0) {
    _DAT_00ddb508 = 0x32545844;
    puVar5 = &DAT_007fb9e8;
  }
  else {
    _DAT_00ddb508 = DAT_00ddb4f8;
    puVar5 = &DAT_007fba20;
  }
  FUN_0056bc00(&DAT_007fb9c4,puVar5);
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x33545844);
  if (iVar3 == 0) {
    _DAT_00ddb50c = 0x33545844;
    puVar5 = &DAT_007fb9b0;
  }
  else {
    _DAT_00ddb50c = DAT_00ddb4f8;
    puVar5 = &DAT_007fba20;
  }
  FUN_0056bc00(&DAT_007fb98c,puVar5);
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x34545844);
  if (iVar3 == 0) {
    _DAT_00ddb510 = 0x34545844;
    puVar5 = &DAT_007fb978;
  }
  else {
    _DAT_00ddb510 = DAT_00ddb4f8;
    puVar5 = &DAT_007fba20;
  }
  FUN_0056bc00(&DAT_007fb954,puVar5);
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x35545844);
  if (iVar3 == 0) {
    _DAT_00ddb514 = 0x35545844;
    puVar5 = &DAT_007fb940;
  }
  else {
    _DAT_00ddb514 = DAT_00ddb4f8;
    puVar5 = &DAT_007fba20;
  }
  FUN_0056bc00(&DAT_007fb91c,puVar5);
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x24);
  if (iVar3 == 0) {
    _DAT_00ddb52c = 0x24;
    FUN_0056bc00(&DAT_007fb8d4,"D3DFMT_A16B16G16R16");
  }
  else {
    FUN_0056bb10(&DAT_007fb210);
    _DAT_00ddb52c = 0;
  }
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x71);
  if (iVar3 == 0) {
    _DAT_00ddb530 = 0x71;
    FUN_0056bc00(&DAT_007fb884,"D3DFMT_A16B16G16R16F");
  }
  else {
    FUN_0056bb10(&DAT_007fb1c0);
    _DAT_00ddb530 = 0;
  }
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x74);
  if (iVar3 == 0) {
    _DAT_00ddb534 = 0x74;
    pcVar8 = "D3DFMT_A32B32G32R32F";
LAB_0059921d:
    FUN_0056bc00(&DAT_007fb834,pcVar8);
  }
  else {
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x71);
    if (iVar3 == 0) {
      _DAT_00ddb534 = 0x71;
      pcVar8 = "D3DFMT_A16B16G16R16F";
      goto LAB_0059921d;
    }
    FUN_0056bb10(&DAT_007fb170);
    _DAT_00ddb534 = 0;
  }
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x15);
  if (iVar3 == 0) {
    _DAT_00ddb538 = 0x15;
    FUN_0056bc00(&DAT_007fb7fc,"D3DFMT_A8R8G8B8");
  }
  else {
    FUN_0056bb10(&DAT_007fb120);
    _DAT_00ddb538 = 0;
  }
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x22);
  if (iVar3 == 0) {
    _DAT_00ddb53c = 0x22;
    pcVar8 = "D3DFMT_G16R16";
LAB_00599294:
    FUN_0056bc00(&DAT_007fb7b0,pcVar8);
  }
  else {
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x24);
    if (iVar3 == 0) {
      _DAT_00ddb53c = 0x24;
      pcVar8 = "D3DFMT_A16B16G16R16";
      goto LAB_00599294;
    }
    FUN_0056bb10(&DAT_007fb0d0);
    _DAT_00ddb53c = 0;
  }
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x6f);
  if (iVar3 == 0) {
    _DAT_00ddb540 = 0x6f;
    pcVar8 = "D3DFMT_R16F";
LAB_005992d0:
    FUN_0056bc00(&DAT_007fb764,pcVar8);
  }
  else {
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x70);
    if (iVar3 == 0) {
      _DAT_00ddb540 = 0x70;
      pcVar8 = "D3DFMT_G16R16F";
      goto LAB_005992d0;
    }
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x71);
    if (iVar3 == 0) {
      _DAT_00ddb540 = 0x71;
      pcVar8 = "D3DFMT_A16B16G16R16F";
      goto LAB_005992d0;
    }
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x74);
    if (iVar3 == 0) {
      _DAT_00ddb540 = 0x74;
      pcVar8 = "D3DFMT_A32B32G32R32F";
      goto LAB_005992d0;
    }
    FUN_0056bb10(&DAT_007fb078);
    _DAT_00ddb540 = 0;
  }
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x72);
  if (iVar3 == 0) {
    _DAT_00ddb544 = 0x72;
    pcVar8 = "D3DFMT_R32F";
LAB_00599310:
    FUN_0056bc00(&DAT_007fb718,pcVar8);
  }
  else {
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x73);
    if (iVar3 == 0) {
      _DAT_00ddb544 = 0x73;
      pcVar8 = "D3DFMT_G32R32F";
      goto LAB_00599310;
    }
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x74);
    if (iVar3 == 0) {
      _DAT_00ddb544 = 0x74;
      pcVar8 = "D3DFMT_A32B32G32R32F";
      goto LAB_00599310;
    }
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x71);
    if (iVar3 == 0) {
      _DAT_00ddb544 = 0x71;
      pcVar8 = "D3DFMT_A16B16G16R16F";
      goto LAB_00599310;
    }
    FUN_0056bb10(&DAT_007fb020);
    _DAT_00ddb544 = 0;
  }
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x15);
  if (iVar3 == 0) {
    _DAT_00ddb548 = 0x15;
    FUN_0056bc00(&DAT_007fb6d0,"D3DFMT_A8B8G8R8");
  }
  else {
    FUN_0056bb10(&DAT_007fafd0);
    _DAT_00ddb548 = 0;
  }
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x22);
  if (iVar3 == 0) {
    _DAT_00ddb54c = 0x22;
    pcVar8 = "D3DFMT_G16R16";
LAB_00599388:
    FUN_0056bc00(&DAT_007fb694,pcVar8);
  }
  else {
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x24);
    if (iVar3 == 0) {
      _DAT_00ddb54c = 0x24;
      pcVar8 = "D3DFMT_A16B16G16R16";
      goto LAB_00599388;
    }
    FUN_0056bb10(&DAT_007faf80);
    _DAT_00ddb54c = 0;
  }
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x70);
  if (iVar3 == 0) {
    _DAT_00ddb550 = 0x70;
    pcVar8 = "D3DFMT_G16R16F";
LAB_005993c4:
    FUN_0056bc00(&DAT_007fb644,pcVar8);
  }
  else {
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x71);
    if (iVar3 == 0) {
      _DAT_00ddb550 = 0x71;
      pcVar8 = "D3DFMT_A16B16G16R16F";
      goto LAB_005993c4;
    }
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x74);
    if (iVar3 == 0) {
      _DAT_00ddb550 = 0x74;
      pcVar8 = "D3DFMT_A32B32G32R32F";
      goto LAB_005993c4;
    }
    FUN_0056bb10(&DAT_007faf28);
    _DAT_00ddb550 = 0;
  }
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x73);
  if (iVar3 == 0) {
    _DAT_00ddb554 = 0x73;
    pcVar8 = "D3DFMT_G32R32F";
LAB_005993fd:
    FUN_0056bc00(&DAT_007fb5f4,pcVar8);
  }
  else {
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x74);
    if (iVar3 == 0) {
      _DAT_00ddb554 = 0x74;
      pcVar8 = "D3DFMT_A32B32G32R32F";
      goto LAB_005993fd;
    }
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0,3,0x71);
    if (iVar3 == 0) {
      _DAT_00ddb554 = 0x71;
      pcVar8 = "D3DFMT_A16B16G16R16F";
      goto LAB_005993fd;
    }
    FUN_0056bb10(&DAT_007faed0);
    _DAT_00ddb554 = 0;
  }
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,1,3,(DAT_00ddb4d0 != 0x17) + '\x17');
  if (iVar3 == 0) {
    DAT_00ddb558 = (DAT_00ddb4d0 != 0x17) + 0x17;
    if (DAT_00ddb4d0 == 0x17) {
LAB_00599453:
      pcVar8 = "D3DFMT_R5G6B5";
    }
    else {
LAB_00599b4a:
      pcVar8 = "D3DFMT_R5G5B5";
    }
    if (DAT_00ddb558 != 0) {
LAB_0059945c:
      FUN_0056bc00(&DAT_007fb5c8,pcVar8);
    }
  }
  else {
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,1,3,(DAT_00ddb4d0 == 0x17) + '\x17');
    if (iVar3 == 0) {
      DAT_00ddb558 = (DAT_00ddb4d0 == 0x17) + 0x17;
      if (DAT_00ddb4d0 == 0x17) goto LAB_00599b4a;
      goto LAB_00599453;
    }
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,1,3,0x16);
    if (iVar3 == 0) {
      DAT_00ddb558 = 0x16;
      pcVar8 = "D3DFMT_X8R8G8B8";
      goto LAB_0059945c;
    }
    FUN_0056bb10(&DAT_007fae78);
    DAT_00ddb558 = 0;
  }
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,1,3,0x16);
  if (iVar3 == 0) {
    DAT_00ddb55c = 0x16;
    pcVar8 = "D3DFMT_X8R8G8B8";
LAB_00599498:
    FUN_0056bc00(&DAT_007fb59c,pcVar8);
  }
  else {
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,1,3,0x17);
    if (iVar3 == 0) {
      DAT_00ddb55c = 0x17;
      pcVar8 = "D3DFMT_R5G6B5";
      goto LAB_00599498;
    }
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,1,3,0x18);
    if (iVar3 == 0) {
      DAT_00ddb55c = 0x18;
      pcVar8 = "D3DFMT_R5G5B5";
      goto LAB_00599498;
    }
    FUN_0056bb10(&DAT_007fae30);
    DAT_00ddb55c = 0;
  }
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,1,3,0x15);
  if (iVar3 == 0) {
    _DAT_00ddb560 = 0x15;
    pcVar8 = "D3DFMT_A8R8G8B8";
LAB_005994d4:
    FUN_0056bc00(&DAT_007fb564,pcVar8);
  }
  else {
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,1,3,0x1a);
    if (iVar3 == 0) {
      _DAT_00ddb560 = 0x1a;
      pcVar8 = "D3DFMT_A4R4G4B4";
      goto LAB_005994d4;
    }
    FUN_0056bb10(&DAT_007fadd8);
    _DAT_00ddb560 = 0;
  }
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,1,3,0x24);
  if (iVar3 == 0) {
    _DAT_00ddb564 = 0x24;
    FUN_0056bc00(&DAT_007fb528,"D3DFMT_A16B16G16R16");
  }
  else {
    FUN_0056bb10(&DAT_007fad88);
    _DAT_00ddb564 = 0;
  }
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,1,3,0x71);
  if (iVar3 == 0) {
    _DAT_00ddb568 = 0x71;
    FUN_0056bc00(&DAT_007fb4e8,"D3DFMT_A16B16G16R16F");
  }
  else {
    FUN_0056bb10(&DAT_007fad30);
    _DAT_00ddb568 = 0;
  }
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,1,3,0x74);
  if (iVar3 == 0) {
    _DAT_00ddb56c = 0x74;
    pcVar8 = "D3DFMT_A32B32G32R32F";
LAB_00599588:
    FUN_0056bc00(&DAT_007fb4a8,pcVar8);
  }
  else {
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,1,3,0x71);
    if (iVar3 == 0) {
      _DAT_00ddb56c = 0x71;
      pcVar8 = "D3DFMT_A16B16G16R16F";
      goto LAB_00599588;
    }
    FUN_0056bb10(&DAT_007facd8);
    _DAT_00ddb56c = 0;
  }
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,1,3,0x32);
  if (iVar3 == 0) {
    _DAT_00ddb570 = 0x32;
    pcVar8 = "D3DFMT_L8";
LAB_005995c9:
    FUN_0056bc00(&DAT_007fb45c,pcVar8);
  }
  else {
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,1,3,0x33);
    if (iVar3 == 0) {
      _DAT_00ddb570 = 0x33;
      pcVar8 = "D3DFMT_A8L8";
      goto LAB_005995c9;
    }
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,1,3,0x15);
    if (iVar3 == 0) {
      _DAT_00ddb570 = 0x15;
      pcVar8 = "D3DFMT_A8R8G8B8";
      goto LAB_005995c9;
    }
    FUN_0056bb10(&DAT_007fac80);
    _DAT_00ddb570 = 0;
  }
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,1,3,0x51);
  if (iVar3 == 0) {
    DAT_00ddb574 = 0x51;
    pcVar8 = "D3DFMT_L16";
LAB_00599605:
    FUN_0056bc00(&DAT_007fb410,pcVar8);
  }
  else {
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,1,3,0x22);
    if (iVar3 == 0) {
      DAT_00ddb574 = 0x22;
      pcVar8 = "D3DFMT_G16R16";
      goto LAB_00599605;
    }
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,1,3,0x24);
    if (iVar3 == 0) {
      DAT_00ddb574 = 0x24;
      pcVar8 = "D3DFMT_A16B16G16R16";
      goto LAB_00599605;
    }
    FUN_0056bb10(&DAT_007fac28);
    DAT_00ddb574 = 0;
  }
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,1,3,0x6f);
  if (iVar3 == 0) {
    DAT_00ddb578 = 0x6f;
    pcVar8 = "D3DFMT_R16F";
LAB_00599641:
    FUN_0056bc00(&DAT_007fb3c8,pcVar8);
  }
  else {
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,1,3,0x70);
    if (iVar3 == 0) {
      DAT_00ddb578 = 0x70;
      pcVar8 = "D3DFMT_G16R16F";
      goto LAB_00599641;
    }
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,1,3,0x71);
    if (iVar3 == 0) {
      DAT_00ddb578 = 0x71;
      pcVar8 = "D3DFMT_A16B16G16R16F";
      goto LAB_00599641;
    }
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,1,3,0x74);
    if (iVar3 == 0) {
      DAT_00ddb578 = 0x74;
      pcVar8 = "D3DFMT_A32B32G32R32F";
      goto LAB_00599641;
    }
    FUN_0056bb10(&DAT_007fabc8);
    DAT_00ddb578 = 0;
  }
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,1,3,0x72);
  if (iVar3 == 0) {
    DAT_00ddb57c = 0x72;
    pcVar8 = "D3DFMT_R32F";
LAB_00599679:
    FUN_0056bc00(&DAT_007fb380,pcVar8);
  }
  else {
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,1,3,0x73);
    if (iVar3 == 0) {
      DAT_00ddb57c = 0x73;
      pcVar8 = "D3DFMT_G32R32F";
      goto LAB_00599679;
    }
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,1,3,0x74);
    if (iVar3 == 0) {
      DAT_00ddb57c = 0x74;
      pcVar8 = "D3DFMT_A32B32G32R32F";
      goto LAB_00599679;
    }
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,1,3,0x71);
    if (iVar3 == 0) {
      DAT_00ddb57c = 0x71;
      pcVar8 = "D3DFMT_A16B16G16R16F";
      goto LAB_00599679;
    }
    FUN_0056bb10(&DAT_007fab68);
    DAT_00ddb57c = 0;
  }
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,1,3,0x33);
  if (iVar3 == 0) {
    _DAT_00ddb580 = 0x33;
    pcVar8 = "D3DFMT_A8L8";
LAB_005996b3:
    FUN_0056bc00(&DAT_007fb330,pcVar8);
  }
  else {
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,1,3,0x15);
    if (iVar3 == 0) {
      _DAT_00ddb580 = 0x15;
      pcVar8 = "D3DFMT_A8B8G8R8";
      goto LAB_005996b3;
    }
    FUN_0056bb10(&DAT_007fab10);
    _DAT_00ddb580 = 0;
  }
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,1,3,0x22);
  if (iVar3 == 0) {
    _DAT_00ddb584 = 0x22;
    pcVar8 = "D3DFMT_G16R16";
LAB_005996f0:
    FUN_0056bc00(&DAT_007fb2f0,pcVar8);
  }
  else {
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,1,3,0x24);
    if (iVar3 == 0) {
      _DAT_00ddb584 = 0x24;
      pcVar8 = "D3DFMT_A16B16G16R16";
      goto LAB_005996f0;
    }
    FUN_0056bb10(&DAT_007faab8);
    _DAT_00ddb584 = 0;
  }
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,1,3,0x70);
  if (iVar3 == 0) {
    _DAT_00ddb588 = 0x70;
    pcVar8 = "D3DFMT_G16R16F";
LAB_0059972c:
    FUN_0056bc00(&DAT_007fb2a8,pcVar8);
  }
  else {
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,1,3,0x71);
    if (iVar3 == 0) {
      _DAT_00ddb588 = 0x71;
      pcVar8 = "D3DFMT_A16B16G16R16F";
      goto LAB_0059972c;
    }
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,1,3,0x74);
    if (iVar3 == 0) {
      _DAT_00ddb588 = 0x74;
      pcVar8 = "D3DFMT_A32B32G32R32F";
      goto LAB_0059972c;
    }
    FUN_0056bb10(&DAT_007faa58);
    _DAT_00ddb588 = 0;
  }
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,1,3,0x73);
  if (iVar3 == 0) {
    _DAT_00ddb58c = 0x73;
    pcVar8 = "D3DFMT_G32R32F";
  }
  else {
    iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,1,3,0x74);
    if (iVar3 == 0) {
      _DAT_00ddb58c = 0x74;
      pcVar8 = "D3DFMT_A32B32G32R32F";
    }
    else {
      iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,1,3,0x71);
      if (iVar3 != 0) {
        FUN_0056bb10(&DAT_007fa9f8);
        _DAT_00ddb58c = 0;
        goto LAB_00599776;
      }
      _DAT_00ddb58c = 0x71;
      pcVar8 = "D3DFMT_A16B16G16R16F";
    }
  }
  FUN_0056bc00(&DAT_007fb260,pcVar8);
LAB_00599776:
  if (DAT_00a37e70 == 0x20) {
    DAT_00ddb590 = DAT_00ddb55c;
    DAT_00ddb594 = DAT_00ddb500;
  }
  else {
    DAT_00ddb590 = DAT_00ddb558;
    DAT_00ddb594 = DAT_00ddb4fc;
  }
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0x100000,3,0x15);
  if (iVar3 == 0) {
    puVar5 = &DAT_007fa9a8;
  }
  else {
    puVar5 = &DAT_007fa958;
  }
  FUN_0056bb10(puVar5);
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0x100000,3,0x16);
  if (iVar3 == 0) {
    puVar5 = &DAT_007fa908;
  }
  else {
    puVar5 = &DAT_007fa8b8;
  }
  FUN_0056bb10(puVar5);
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0x100000,3,0x17);
  if (iVar3 == 0) {
    puVar5 = &DAT_007fa868;
  }
  else {
    puVar5 = &DAT_007fa818;
  }
  FUN_0056bb10(puVar5);
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0x100000,3,0x19);
  if (iVar3 == 0) {
    puVar5 = &DAT_007fa7c8;
  }
  else {
    puVar5 = &DAT_007fa778;
  }
  FUN_0056bb10(puVar5);
  iVar3 = FUN_005d3420(uVar7,1,DAT_00ddb4d0,0x100000,3,0x18);
  if (iVar3 == 0) {
    puVar5 = &DAT_007fa728;
  }
  else {
    puVar5 = &DAT_007fa6d8;
  }
  FUN_0056bb10(puVar5);
  FUN_0056bc00(&DAT_007fa6ac,DAT_00a37dc0);
  FUN_0056bc00(&DAT_007fa688,DAT_00a37dc4);
  FUN_0056bc00(&DAT_007fa660,DAT_00a37da8);
  FUN_0056bc00(&DAT_007fa63c,DAT_00ddb3d8,DAT_00ddb3dc);
  puVar5 = &DAT_007fa634;
  if (DAT_00ddb4b8 == 0) {
    puVar5 = &DAT_007fa628;
  }
  FUN_0056bc00(&DAT_007fa5fc,puVar5);
  puVar5 = &DAT_007fa5f0;
  if (DAT_00ddb4bc == 0) {
    puVar5 = &DAT_007fa5e0;
  }
  FUN_0056bc00(&DAT_007fa5c0,puVar5);
  if (DAT_00ddb4b0 == 0) {
    FUN_0056bc00(&DAT_007fa590,DAT_00ddb5ec);
    FUN_0056bc00(&DAT_007fa510,DAT_00ddb444 & 0xffff);
  }
  else {
    FUN_0056bc00(&DAT_007fa590,DAT_00ddb444 & 0xffff);
    FUN_0056bc00(&DAT_007fa548);
  }
  FUN_0056bc00(&DAT_007fa4e8,DAT_00ddb44c & 0xffff);
  pcStack_4f4 = (char *)0x0;
  iStack_4f0 = 0;
  iStack_4ec = 0;
  DAT_00ddb4c0 = 0;
  if (DAT_00a37d84 != 0) {
    FUN_0056bb10(&DAT_007fa498);
    return 0;
  }
  iStack_4d4 = 3;
  do {
    uStack_4e8._0_4_ = 0xffffffff;
    uStack_4e8._4_4_ = 0xffffffff;
    uStack_4cc = 0xffffffff;
    for (uVar7 = 0x100; (DAT_00a37e60 < uVar7 || (DAT_00a37e64 < uVar7)); uVar7 = uVar7 >> 1) {
    }
    iStack_4ec = 0;
    iVar3 = FUN_005d38a0(uVar7,uVar7,DAT_00ddb4d0,2,&iStack_4ec,0);
    lVar10 = CONCAT44(uStack_4cc,0xffffffff);
    if (iVar3 == 0) {
      aiStack_4c0[0] = 0;
      aiStack_4c0[1] = 0;
      aiStack_4c0[2] = uVar7;
      uStack_4b4 = uVar7;
      iVar3 = FUN_00598180(DAT_00ddb4d0);
      iVar4 = FUN_005d4b80(iStack_4ec,&iStack_4c8,aiStack_4c0,0x10);
      lVar10 = CONCAT44(uStack_4cc,0xffffffff);
      if (iVar4 == 0) {
        uStack_4e8 = FUN_00550090(0);
        iVar4 = FUN_005d4b80(DAT_00ddb5b4,&iStack_4dc,aiStack_4c0,0x10);
        lVar10 = CONCAT44(uStack_4cc,0xffffffff);
        if (iVar4 == 0) {
          uVar9 = 0;
          if (uVar7 != 0) {
            do {
              FUN_0056d420(iStack_4c8 * uVar9 + iStack_4c4,iStack_4dc * uVar9 + iStack_4d8,
                           *(byte *)(iVar3 + 4) * uVar7);
              uVar9 = uVar9 + 1;
            } while (uVar9 < uVar7);
          }
          FUN_005d4ba0(DAT_00ddb5b4);
          lVar10 = FUN_00550090(0);
          uStack_4e8 = lVar10 - uStack_4e8;
          uVar11 = FUN_00550090(0);
          uStack_4cc = (uint)((ulonglong)uVar11 >> 0x20);
          uVar6 = (undefined4)uVar11;
          iVar4 = FUN_005d3790(uVar7,uVar7,DAT_00ddb4d0,0,0,0,&pcStack_4f4,0);
          lVar10 = CONCAT44(uStack_4cc,uVar6);
          if (iVar4 == 0) {
            iVar4 = FUN_005d38a0(uVar7,uVar7,DAT_00ddb4d0,2,&iStack_4f0,0);
            lVar10 = CONCAT44(uStack_4cc,uVar6);
            if (iVar4 == 0) {
              FUN_005d3850(DAT_00ddb5b4,aiStack_4c0,pcStack_4f4,aiStack_4c0,0);
              FUN_005d3830(pcStack_4f4,iStack_4f0);
              iVar4 = FUN_005d4b80(iStack_4f0,&iStack_4dc,0,0x10);
              lVar10 = CONCAT44(uStack_4cc,uVar6);
              if (iVar4 == 0) {
                if (uVar7 != 0) {
                  uVar9 = 0;
                  do {
                    FUN_0056d420(iStack_4c8 * uVar9 + iStack_4c4,iStack_4dc * uVar9 + iStack_4d8,
                                 *(byte *)(iVar3 + 4) * uVar7);
                    uVar9 = uVar9 + 1;
                  } while (uVar9 < uVar7);
                }
                FUN_005d4ba0(iStack_4f0);
                FUN_005d3370(pcStack_4f4);
                FUN_005d3370(iStack_4f0);
                pcStack_4f4 = (char *)0x0;
                iStack_4f0 = 0;
                lVar10 = FUN_00550090(0);
                lVar10 = lVar10 - CONCAT44(uStack_4cc,uVar6);
              }
            }
          }
        }
      }
    }
    uStack_4cc = (uint)((ulonglong)lVar10 >> 0x20);
    uVar7 = (uint)lVar10;
    if (iStack_4f0 != 0) {
      FUN_005d3370(iStack_4f0);
      iStack_4f0 = 0;
    }
    if (pcStack_4f4 != (char *)0x0) {
      FUN_005d3370(pcStack_4f4);
      pcStack_4f4 = (char *)0x0;
    }
    lVar10 = uStack_4e8;
    if (iStack_4ec != 0) {
      FUN_005d3370(iStack_4ec);
      iStack_4ec = 0;
      lVar10 = uStack_4e8;
    }
    lVar1 = CONCAT44(uStack_4cc,uVar7);
    uStack_4e8._0_4_ = (undefined4)lVar10;
    iStack_4d4 = iStack_4d4 + -1;
  } while (iStack_4d4 != 0);
  if (((uVar7 & uStack_4cc) == 0xffffffff) || (lVar10 == -1)) {
    uStack_4e8 = lVar10;
    FUN_0056bb10(&DAT_007fa3b4);
    return 0;
  }
  lVar2 = lVar10;
  FUN_0056bca0(&DAT_007fa428,(undefined4)uStack_4e8,uVar7);
  uStack_4e8 = lVar2;
  if (lVar10 < lVar1) {
    DAT_00ddb4c0 = 1;
    FUN_0056bb10(&DAT_007fa400);
    return 0;
  }
  FUN_0056bb10(&DAT_007fa3d8);
  return 0;
}

