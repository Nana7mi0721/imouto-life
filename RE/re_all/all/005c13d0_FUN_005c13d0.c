
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005c13d0(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined *puVar4;
  char *pcVar5;
  uint local_4;
  
  FUN_005d5560();
  DAT_00f07348 = 0;
  iVar1 = FUN_005d5440();
  if (((iVar1 < 0) || (iVar1 = FUN_005b8fa0(), iVar1 < 0)) || (iVar1 = FUN_005d23f0(), iVar1 < 0)) {
    return 0xffffffff;
  }
  uVar2 = FUN_0050eb30(1);
  iVar1 = FUN_005c0df0(uVar2);
  if (iVar1 < 0) {
    return 0xffffffff;
  }
  DAT_00ef1b48 = 0;
  iVar1 = FUN_0050e7d0();
  if (iVar1 == 0) {
    puVar3 = (undefined4 *)((-(uint)(DAT_00a37eec != 0) & _DAT_00a37ef0) * 0x130 + DAT_00a37ef8);
    _DAT_00a37eac = *puVar3;
    _DAT_00a37eb0 = puVar3[1];
    _DAT_00a37eb4 = puVar3[2];
    _DAT_00a37eb8 = puVar3[3];
  }
  DAT_00a37d8c = 1;
  DAT_00a37da4 = 0;
  DAT_00a37dc4 = 0xffff;
  DAT_00a37dd0 = 1;
  iVar1 = 0x4000;
  if (DAT_00ee9a3c < 0xa001) {
    if (DAT_00ee9a3c == 0xa000) {
LAB_005c156f:
      iVar1 = 0x2000;
      goto LAB_005c153a;
    }
    if (((DAT_00ee9a3c == 0x9100) || (DAT_00ee9a3c == 0x9200)) || (DAT_00ee9a3c == 0x9300)) {
      DAT_00a37da8 = (-(uint)(DAT_00ee9a3c != 0x9300) & 0xfffffffd) + 4;
      DAT_00a37db8 = (-(uint)(DAT_00ee9a3c != 0x9300) & 0xfffff800) + 0x1000;
      DAT_00a37dc0 = (-(uint)(DAT_00ee9a3c != 0x9100) & 0xf0000) + 0xffff;
      DAT_00a37dac = 1;
      DAT_00ee9a30 = 0;
      DAT_00a37dcc = 0;
      DAT_00a37dbc = DAT_00a37db8;
      goto LAB_005c1590;
    }
LAB_005c1576:
    DAT_00a37db4 = DAT_00a37db8;
    if (DAT_00a37dbc <= DAT_00a37db8) goto LAB_005c1590;
  }
  else {
    if (DAT_00ee9a3c == 0xa100) goto LAB_005c156f;
    if ((DAT_00ee9a3c != 0xb000) && (DAT_00ee9a3c != 0xb100)) goto LAB_005c1576;
LAB_005c153a:
    DAT_00a37da8 = 8;
    DAT_00a37db0 = 0;
    DAT_00a37dac = 1;
    DAT_00a37dcc = 1;
    DAT_00a37dc0 = 0x7fffffff;
    DAT_00a37db8 = iVar1;
    DAT_00a37dbc = iVar1;
LAB_005c1590:
    DAT_00a37db4 = DAT_00a37dbc;
  }
  if (8 < DAT_00a37da8) {
    DAT_00a37da8 = 8;
  }
  DAT_00ef72cc = 1;
  FUN_0056bc50(L"Graphics Device:%s",&DAT_00f1392c);
  DAT_00ee9a54 = 0x1c;
  FUN_0056bc00(&DAT_007fbc20,"DXGI_FORMAT_R8G8B8A8_UNORM");
  pcVar5 = "DXGI_FORMAT_D16_UNORM";
  DAT_00ee9b1c = 0x37;
  DAT_00ee9b28 = 0x37;
  FUN_0056bc00(&DAT_007fbbec,"DXGI_FORMAT_D16_UNORM");
  iVar1 = FUN_005d2a00(0x2d,&local_4);
  if ((iVar1 == 0) && ((local_4 & 0x10000) != 0)) {
    DAT_00ee9b20 = 0x2c;
    DAT_00ee9b2c = 0x2d;
    pcVar5 = "DXGI_FORMAT_D24_UNORM_S8_UINT";
  }
  else {
    DAT_00ee9b20 = DAT_00ee9b1c;
    DAT_00ee9b2c = DAT_00ee9b28;
  }
  FUN_0056bc00(&DAT_007fbba8,pcVar5);
  iVar1 = FUN_005d2a00(0x28,&local_4);
  if ((iVar1 == 0) && ((local_4 & 0x10000) != 0)) {
    _DAT_00ee9b24 = 0x27;
    _DAT_00ee9b30 = 0x28;
    pcVar5 = "DXGI_FORMAT_D32_FLOAT";
  }
  else {
    _DAT_00ee9b24 = DAT_00ee9b20;
    _DAT_00ee9b30 = DAT_00ee9b2c;
  }
  FUN_0056bc00(&DAT_007fbb80,pcVar5);
  iVar1 = FUN_005d2a00(0x1c,&local_4);
  if ((iVar1 != 0) || ((local_4 & 0x20) == 0)) {
    FUN_0056ba10(&DAT_007fdfa4);
    return 0xffffffff;
  }
  _DAT_00ee9a70 = 0x1c;
  _DAT_00ee9a74 = 0x1c;
  _DAT_00ee9a78 = 0x1c;
  DAT_00ee9a7c = 0x1c;
  DAT_00ee9a80 = 0x1c;
  _DAT_00ee9a84 = 0x1c;
  FUN_0056bc00(&DAT_007feacc,"DXGI_FORMAT_R8G8B8A8_UNORM");
  _DAT_00ee9a58 = 0x1c;
  _DAT_00ee9a5c = 0x1c;
  _DAT_00ee9a60 = 0x1c;
  _DAT_00ee9a64 = 0x1c;
  _DAT_00ee9a68 = 0x1c;
  _DAT_00ee9a6c = 0x1c;
  iVar1 = FUN_005d2a00(0x47,&local_4);
  if ((iVar1 == 0) && ((local_4 & 0x20) != 0)) {
    _DAT_00ee9a88 = 0x47;
    puVar4 = &DAT_007feab0;
  }
  else {
    _DAT_00ee9a88 = DAT_00ee9a80;
    puVar4 = &DAT_007fba20;
  }
  FUN_0056bc00(&DAT_007fb9fc,puVar4);
  _DAT_00ee9a8c = DAT_00ee9a7c;
  FUN_0056bc00(&DAT_007fea84);
  iVar1 = FUN_005d2a00(0x4a,&local_4);
  if ((iVar1 == 0) && ((local_4 & 0x20) != 0)) {
    _DAT_00ee9a90 = 0x4a;
    puVar4 = &DAT_007fea68;
  }
  else {
    _DAT_00ee9a90 = DAT_00ee9a7c;
    puVar4 = &DAT_007fba20;
  }
  FUN_0056bc00(&DAT_007fb98c,puVar4);
  _DAT_00ee9a94 = DAT_00ee9a7c;
  FUN_0056bc00(&DAT_007fea3c);
  iVar1 = FUN_005d2a00(0x4d,&local_4);
  if ((iVar1 == 0) && ((local_4 & 0x20) != 0)) {
    _DAT_00ee9a98 = 0x4d;
    pcVar5 = &DAT_007fea20;
  }
  else {
    _DAT_00ee9a98 = DAT_00ee9a7c;
    pcVar5 = &DAT_007fba20;
  }
  FUN_0056bc00(&DAT_007fb91c,pcVar5);
  iVar1 = FUN_005d2a00(0xb,&local_4);
  if ((iVar1 == 0) && ((local_4 & 0x20) != 0)) {
    pcVar5 = "DXGI_FORMAT_R16G16B16A16_UNORM";
    _DAT_00ee9ab0 = 0xb;
    FUN_0056bc00(&DAT_007fb8d4,"DXGI_FORMAT_R16G16B16A16_UNORM");
  }
  else {
    FUN_0056ba10(&DAT_007fe868);
    _DAT_00ee9ab0 = 0;
  }
  iVar1 = FUN_005d2a00(10,&local_4);
  if ((iVar1 == 0) && ((local_4 & 0x20) != 0)) {
    pcVar5 = "DXGI_FORMAT_R16G16B16A16_FLOAT";
    _DAT_00ee9ab4 = 10;
    FUN_0056bc00(&DAT_007fb884,"DXGI_FORMAT_R16G16B16A16_FLOAT");
  }
  else {
    FUN_0056ba10(&DAT_007fe818);
    _DAT_00ee9ab4 = 0;
  }
  iVar1 = FUN_005d2a00(2,&local_4);
  if ((iVar1 == 0) && ((local_4 & 0x20) != 0)) {
    _DAT_00ee9ab8 = 2;
    pcVar5 = "DXGI_FORMAT_R32G32B32A32_FLOAT";
LAB_005c18cc:
    FUN_0056bc00(&DAT_007fb834,pcVar5);
  }
  else {
    iVar1 = FUN_005d2a00(10,&local_4);
    if ((iVar1 == 0) && ((local_4 & 0x20) != 0)) {
      _DAT_00ee9ab8 = 10;
      pcVar5 = "DXGI_FORMAT_R16G16B16A16_FLOAT";
      goto LAB_005c18cc;
    }
    FUN_0056ba10(&DAT_007fe7c8);
    _DAT_00ee9ab8 = 0;
  }
  iVar1 = FUN_005d2a00(0x3d,&local_4);
  if ((iVar1 == 0) && ((local_4 & 0x20) != 0)) {
    _DAT_00ee9abc = 0x3d;
    pcVar5 = "DXGI_FORMAT_R8_UNORM";
LAB_005c190d:
    FUN_0056bc00(&DAT_007fb7fc,pcVar5);
  }
  else {
    iVar1 = FUN_005d2a00(0x31,&local_4);
    if ((iVar1 == 0) && ((local_4 & 0x20) != 0)) {
      _DAT_00ee9abc = 0x31;
      pcVar5 = "DXGI_FORMAT_R8G8_UNORM";
      goto LAB_005c190d;
    }
    iVar1 = FUN_005d2a00(0x1c,&local_4);
    if ((iVar1 == 0) && ((local_4 & 0x20) != 0)) {
      _DAT_00ee9abc = 0x1c;
      pcVar5 = "DXGI_FORMAT_R8G8B8A8_UNORM";
      goto LAB_005c190d;
    }
    FUN_0056ba10(&DAT_007fe778);
    _DAT_00ee9abc = 0;
  }
  iVar1 = FUN_005d2a00(0x38,&local_4);
  if ((iVar1 == 0) && ((local_4 & 0x20) != 0)) {
    _DAT_00ee9ac0 = 0x38;
    pcVar5 = "DXGI_FORMAT_R16_UNORM";
LAB_005c194c:
    FUN_0056bc00(&DAT_007fb7b0,pcVar5);
  }
  else {
    iVar1 = FUN_005d2a00(0x23,&local_4);
    if ((iVar1 == 0) && ((local_4 & 0x20) != 0)) {
      _DAT_00ee9ac0 = 0x23;
      pcVar5 = "DXGI_FORMAT_R16G16_UNORM";
      goto LAB_005c194c;
    }
    iVar1 = FUN_005d2a00(0xb,&local_4);
    if ((iVar1 == 0) && ((local_4 & 0x20) != 0)) {
      _DAT_00ee9ac0 = 0xb;
      pcVar5 = "DXGI_FORMAT_R16G16B16A16_UNORM";
      goto LAB_005c194c;
    }
    FUN_0056ba10(&DAT_007fe728);
    _DAT_00ee9ac0 = 0;
  }
  iVar1 = FUN_005d2a00(0x36,&local_4);
  if ((iVar1 == 0) && ((local_4 & 0x20) != 0)) {
    _DAT_00ee9ac4 = 0x36;
    pcVar5 = "DXGI_FORMAT_R16_FLOAT";
LAB_005c198b:
    FUN_0056bc00(&DAT_007fb764,pcVar5);
  }
  else {
    iVar1 = FUN_005d2a00(0x22,&local_4);
    if ((iVar1 == 0) && ((local_4 & 0x20) != 0)) {
      _DAT_00ee9ac4 = 0x22;
      pcVar5 = "DXGI_FORMAT_R16G16_FLOAT";
      goto LAB_005c198b;
    }
    iVar1 = FUN_005d2a00(10,&local_4);
    if ((iVar1 == 0) && ((local_4 & 0x20) != 0)) {
      _DAT_00ee9ac4 = 10;
      pcVar5 = "DXGI_FORMAT_R16G16B16A16_FLOAT";
      goto LAB_005c198b;
    }
    iVar1 = FUN_005d2a00(2,&local_4);
    if ((iVar1 == 0) && ((local_4 & 0x20) != 0)) {
      _DAT_00ee9ac4 = 2;
      pcVar5 = "DXGI_FORMAT_R32G32B32A32_FLOAT";
      goto LAB_005c198b;
    }
    FUN_0056ba10(&DAT_007fe6d0);
    _DAT_00ee9ac4 = 0;
  }
  iVar1 = FUN_005d2a00(0x29,&local_4);
  if ((iVar1 == 0) && ((local_4 & 0x20) != 0)) {
    _DAT_00ee9ac8 = 0x29;
    pcVar5 = "DXGI_FORMAT_R32_FLOAT";
LAB_005c19cf:
    FUN_0056bc00(&DAT_007fb718,pcVar5);
  }
  else {
    iVar1 = FUN_005d2a00(0x10,&local_4);
    if ((iVar1 == 0) && ((local_4 & 0x20) != 0)) {
      _DAT_00ee9ac8 = 0x10;
      pcVar5 = "DXGI_FORMAT_R32G32_FLOAT";
      goto LAB_005c19cf;
    }
    iVar1 = FUN_005d2a00(2,&local_4);
    if ((iVar1 == 0) && ((local_4 & 0x20) != 0)) {
      _DAT_00ee9ac8 = 2;
      pcVar5 = "DXGI_FORMAT_R32G32B32A32_FLOAT";
      goto LAB_005c19cf;
    }
    iVar1 = FUN_005d2a00(10,&local_4);
    if ((iVar1 == 0) && ((local_4 & 0x20) != 0)) {
      _DAT_00ee9ac8 = 10;
      pcVar5 = "DXGI_FORMAT_R16G16B16A16_FLOAT";
      goto LAB_005c19cf;
    }
    FUN_0056ba10(&DAT_007fe678);
    _DAT_00ee9ac8 = 0;
  }
  iVar1 = FUN_005d2a00(0x31,&local_4);
  if ((iVar1 == 0) && ((local_4 & 0x20) != 0)) {
    _DAT_00ee9acc = 0x31;
    pcVar5 = "DXGI_FORMAT_R8G8_UNORM";
LAB_005c1a0e:
    FUN_0056bc00(&DAT_007fb6d0,pcVar5);
  }
  else {
    iVar1 = FUN_005d2a00(0x1c,&local_4);
    if ((iVar1 == 0) && ((local_4 & 0x20) != 0)) {
      _DAT_00ee9acc = 0x1c;
      pcVar5 = "DXGI_FORMAT_R8G8B8A8_UNORM";
      goto LAB_005c1a0e;
    }
    FUN_0056ba10(&DAT_007fe628);
    _DAT_00ee9acc = 0;
  }
  iVar1 = FUN_005d2a00(0x23,&local_4);
  if ((iVar1 == 0) && ((local_4 & 0x20) != 0)) {
    _DAT_00ee9ad0 = 0x23;
    pcVar5 = "DXGI_FORMAT_R16G16_UNORM";
LAB_005c1a4d:
    FUN_0056bc00(&DAT_007fb694,pcVar5);
  }
  else {
    iVar1 = FUN_005d2a00(0xb,&local_4);
    if ((iVar1 == 0) && ((local_4 & 0x20) != 0)) {
      _DAT_00ee9ad0 = 0xb;
      pcVar5 = "DXGI_FORMAT_R16G16B16A16_UNORM";
      goto LAB_005c1a4d;
    }
    FUN_0056ba10(&DAT_007fe5d8);
    _DAT_00ee9ad0 = 0;
  }
  iVar1 = FUN_005d2a00(0x22,&local_4);
  if ((iVar1 == 0) && ((local_4 & 0x20) != 0)) {
    _DAT_00ee9ad4 = 0x22;
    pcVar5 = "DXGI_FORMAT_R16G16_FLOAT";
LAB_005c1a8c:
    FUN_0056bc00(&DAT_007fb644,pcVar5);
  }
  else {
    iVar1 = FUN_005d2a00(10,&local_4);
    if ((iVar1 == 0) && ((local_4 & 0x20) != 0)) {
      _DAT_00ee9ad4 = 10;
      pcVar5 = "DXGI_FORMAT_R16G16B16A16_FLOAT";
      goto LAB_005c1a8c;
    }
    iVar1 = FUN_005d2a00(2,&local_4);
    if ((iVar1 == 0) && ((local_4 & 0x20) != 0)) {
      _DAT_00ee9ad4 = 2;
      pcVar5 = "DXGI_FORMAT_R32G32B32A32_FLOAT";
      goto LAB_005c1a8c;
    }
    FUN_0056ba10(&DAT_007fe580);
    _DAT_00ee9ad4 = 0;
  }
  iVar1 = FUN_005d2a00(0x10,&local_4);
  if ((iVar1 == 0) && ((local_4 & 0x20) != 0)) {
    _DAT_00ee9ad8 = 0x10;
    pcVar5 = "DXGI_FORMAT_R32G32_FLOAT";
LAB_005c1ac6:
    FUN_0056bc00(&DAT_007fb5f4,pcVar5);
  }
  else {
    iVar1 = FUN_005d2a00(2,&local_4);
    if ((iVar1 == 0) && ((local_4 & 0x20) != 0)) {
      _DAT_00ee9ad8 = 2;
      pcVar5 = "DXGI_FORMAT_R32G32B32A32_FLOAT";
      goto LAB_005c1ac6;
    }
    iVar1 = FUN_005d2a00(10,&local_4);
    if ((iVar1 == 0) && ((local_4 & 0x20) != 0)) {
      _DAT_00ee9ad8 = 10;
      pcVar5 = "DXGI_FORMAT_R16G16B16A16_FLOAT";
      goto LAB_005c1ac6;
    }
    FUN_0056ba10(&DAT_007fe528);
    _DAT_00ee9ad8 = 0;
  }
  iVar1 = FUN_005d2a00(0x55,&local_4);
  if (((iVar1 == 0) || ((local_4 & 0x20) != 0)) || ((local_4 & 0x4000) != 0)) {
    DAT_00ee9adc = 0x55;
    pcVar5 = "DXGI_FORMAT_B5G6R5_UNORM";
LAB_005c1fcf:
    FUN_0056bc00(&DAT_007fb5c8,pcVar5);
  }
  else {
    iVar1 = FUN_005d2a00(0x58,&local_4);
    if (((iVar1 == 0) || ((local_4 & 0x20) != 0)) || ((local_4 & 0x4000) != 0)) {
      DAT_00ee9adc = 0x58;
      pcVar5 = "DXGI_FORMAT_B8G8R8X8_UNORM";
      goto LAB_005c1fcf;
    }
    iVar1 = FUN_005d2a00(0x1c,&local_4);
    if (((iVar1 == 0) || ((local_4 & 0x20) != 0)) || ((local_4 & 0x4000) != 0)) {
      DAT_00ee9adc = 0x1c;
      pcVar5 = "DXGI_FORMAT_R8G8B8A8_UNORM";
      goto LAB_005c1fcf;
    }
    FUN_0056ba10(&DAT_007fe8b0);
    DAT_00ee9adc = 0;
  }
  iVar1 = FUN_005d2a00(0x58,&local_4);
  if (((iVar1 == 0) || ((local_4 & 0x20) != 0)) || ((local_4 & 0x4000) != 0)) {
    DAT_00ee9ae0 = 0x58;
    pcVar5 = "DXGI_FORMAT_B8G8R8X8_UNORM";
LAB_005c2055:
    FUN_0056bc00(&DAT_007fb59c,pcVar5);
  }
  else {
    iVar1 = FUN_005d2a00(0x1c,&local_4);
    if (((iVar1 == 0) || ((local_4 & 0x20) != 0)) || ((local_4 & 0x4000) != 0)) {
      DAT_00ee9ae0 = 0x1c;
      pcVar5 = "DXGI_FORMAT_R8G8B8A8_UNORM";
      goto LAB_005c2055;
    }
    FUN_0056ba10(&DAT_007fe4a8);
    DAT_00ee9ae0 = 0;
  }
  iVar1 = FUN_005d2a00(0x1c,&local_4);
  if (((iVar1 == 0) || ((local_4 & 0x20) != 0)) || ((local_4 & 0x4000) != 0)) {
    pcVar5 = "DXGI_FORMAT_R8G8B8A8_UNORM";
    _DAT_00ee9ae4 = 0x1c;
    FUN_0056bc00(&DAT_007fb564,"DXGI_FORMAT_R8G8B8A8_UNORM");
  }
  else {
    FUN_0056ba10(&DAT_007fe458);
    _DAT_00ee9ae4 = 0;
  }
  iVar1 = FUN_005d2a00(0xb,&local_4);
  if (((iVar1 == 0) && ((local_4 & 0x20) != 0)) && ((local_4 & 0x4000) != 0)) {
    pcVar5 = "DXGI_FORMAT_R16G16B16A16_UNORM";
    _DAT_00ee9ae8 = 0xb;
    FUN_0056bc00(&DAT_007fb528,"DXGI_FORMAT_R16G16B16A16_UNORM");
  }
  else {
    FUN_0056ba10(&DAT_007fe408);
    _DAT_00ee9ae8 = 0;
  }
  iVar1 = FUN_005d2a00(10,&local_4);
  if (((iVar1 == 0) && ((local_4 & 0x20) != 0)) && ((local_4 & 0x4000) != 0)) {
    pcVar5 = "DXGI_FORMAT_R16G16B16A16_FLOAT";
    _DAT_00ee9aec = 10;
    FUN_0056bc00(&DAT_007fb4e8,"DXGI_FORMAT_R16G16B16A16_FLOAT");
  }
  else {
    FUN_0056ba10(&DAT_007fe3b0);
    _DAT_00ee9aec = 0;
  }
  iVar1 = FUN_005d2a00(2,&local_4);
  if (((iVar1 == 0) && ((local_4 & 0x20) != 0)) && ((local_4 & 0x4000) != 0)) {
    _DAT_00ee9af0 = 2;
    pcVar5 = "DXGI_FORMAT_R32G32B32A32_FLOAT";
LAB_005c218e:
    FUN_0056bc00(&DAT_007fb4a8,pcVar5);
  }
  else {
    iVar1 = FUN_005d2a00(10,&local_4);
    if (((iVar1 == 0) && ((local_4 & 0x20) != 0)) && ((local_4 & 0x4000) != 0)) {
      _DAT_00ee9af0 = 10;
      pcVar5 = "DXGI_FORMAT_R16G16B16A16_FLOAT";
      goto LAB_005c218e;
    }
    FUN_0056ba10(&DAT_007fe358);
    _DAT_00ee9af0 = 0;
  }
  iVar1 = FUN_005d2a00(0x3d,&local_4);
  if (((iVar1 == 0) && ((local_4 & 0x20) != 0)) && ((local_4 & 0x4000) != 0)) {
    _DAT_00ee9af4 = 0x3d;
    pcVar5 = "DXGI_FORMAT_R8_UNORM";
LAB_005c21d9:
    FUN_0056bc00(&DAT_007fb45c,pcVar5);
  }
  else {
    iVar1 = FUN_005d2a00(0x31,&local_4);
    if (((iVar1 == 0) && ((local_4 & 0x20) != 0)) && ((local_4 & 0x4000) != 0)) {
      _DAT_00ee9af4 = 0x31;
      pcVar5 = "DXGI_FORMAT_R8G8_UNORM";
      goto LAB_005c21d9;
    }
    iVar1 = FUN_005d2a00(0x1c,&local_4);
    if (((iVar1 == 0) && ((local_4 & 0x20) != 0)) && ((local_4 & 0x4000) != 0)) {
      _DAT_00ee9af4 = 0x1c;
      pcVar5 = "DXGI_FORMAT_R8G8B8A8_UNORM";
      goto LAB_005c21d9;
    }
    FUN_0056ba10(&DAT_007fe300);
    _DAT_00ee9af4 = 0;
  }
  iVar1 = FUN_005d2a00(0x38,&local_4);
  if (((iVar1 == 0) && ((local_4 & 0x20) != 0)) && ((local_4 & 0x4000) != 0)) {
    DAT_00ee9af8 = 0x38;
    pcVar5 = "DXGI_FORMAT_R16_UNORM";
LAB_005c221f:
    FUN_0056bc00(&DAT_007fb410,pcVar5);
  }
  else {
    iVar1 = FUN_005d2a00(0x23,&local_4);
    if (((iVar1 == 0) && ((local_4 & 0x20) != 0)) && ((local_4 & 0x4000) != 0)) {
      DAT_00ee9af8 = 0x23;
      pcVar5 = "DXGI_FORMAT_R16G16_UNORM";
      goto LAB_005c221f;
    }
    iVar1 = FUN_005d2a00(0xb,&local_4);
    if (((iVar1 == 0) && ((local_4 & 0x20) != 0)) && ((local_4 & 0x4000) != 0)) {
      DAT_00ee9af8 = 0xb;
      pcVar5 = "DXGI_FORMAT_R16G16B16A16_UNORM";
      goto LAB_005c221f;
    }
    FUN_0056ba10(&DAT_007fe2a8);
    DAT_00ee9af8 = 0;
  }
  iVar1 = FUN_005d2a00(0x36,&local_4);
  if (((iVar1 == 0) && ((local_4 & 0x20) != 0)) && ((local_4 & 0x4000) != 0)) {
    DAT_00ee9afc = 0x36;
    pcVar5 = "DXGI_FORMAT_R16_FLOAT";
LAB_005c226c:
    FUN_0056bc00(&DAT_007fb3c8,pcVar5);
  }
  else {
    iVar1 = FUN_005d2a00(0x22,&local_4);
    if (((iVar1 == 0) && ((local_4 & 0x20) != 0)) && ((local_4 & 0x4000) != 0)) {
      DAT_00ee9afc = 0x22;
      pcVar5 = "DXGI_FORMAT_R16G16_FLOAT";
      goto LAB_005c226c;
    }
    iVar1 = FUN_005d2a00(10,&local_4);
    if (((iVar1 == 0) && ((local_4 & 0x20) != 0)) && ((local_4 & 0x4000) != 0)) {
      DAT_00ee9afc = 10;
      pcVar5 = "DXGI_FORMAT_R16G16B16A16_FLOAT";
      goto LAB_005c226c;
    }
    iVar1 = FUN_005d2a00(2,&local_4);
    if (((iVar1 == 0) && ((local_4 & 0x20) != 0)) && ((local_4 & 0x4000) != 0)) {
      DAT_00ee9afc = 2;
      pcVar5 = "DXGI_FORMAT_R32G32B32A32_FLOAT";
      goto LAB_005c226c;
    }
    FUN_0056ba10(&DAT_007fe250);
    DAT_00ee9afc = 0;
  }
  iVar1 = FUN_005d2a00(0x29,&local_4);
  if (((iVar1 == 0) && ((local_4 & 0x20) != 0)) && ((local_4 & 0x4000) != 0)) {
    DAT_00ee9b00 = 0x29;
    pcVar5 = "DXGI_FORMAT_R32_FLOAT";
LAB_005c22b7:
    FUN_0056bc00(&DAT_007fb380,pcVar5);
  }
  else {
    iVar1 = FUN_005d2a00(0x10,&local_4);
    if (((iVar1 == 0) && ((local_4 & 0x20) != 0)) && ((local_4 & 0x4000) != 0)) {
      DAT_00ee9b00 = 0x10;
      pcVar5 = "DXGI_FORMAT_R32G32_FLOAT";
      goto LAB_005c22b7;
    }
    iVar1 = FUN_005d2a00(2,&local_4);
    if (((iVar1 == 0) && ((local_4 & 0x20) != 0)) && ((local_4 & 0x4000) != 0)) {
      DAT_00ee9b00 = 2;
      pcVar5 = "DXGI_FORMAT_R32G32B32A32_FLOAT";
      goto LAB_005c22b7;
    }
    iVar1 = FUN_005d2a00(10,&local_4);
    if (((iVar1 == 0) && ((local_4 & 0x20) != 0)) && ((local_4 & 0x4000) != 0)) {
      DAT_00ee9b00 = 10;
      pcVar5 = "DXGI_FORMAT_R16G16B16A16_FLOAT";
      goto LAB_005c22b7;
    }
    FUN_0056ba10(&DAT_007fe1f8);
    DAT_00ee9b00 = 0;
  }
  iVar1 = FUN_005d2a00(0x31,&local_4);
  if (((iVar1 == 0) && ((local_4 & 0x20) != 0)) && ((local_4 & 0x4000) != 0)) {
    _DAT_00ee9b04 = 0x31;
    pcVar5 = "DXGI_FORMAT_R8G8_UNORM";
LAB_005c2302:
    FUN_0056bc00(&DAT_007fb330,pcVar5);
  }
  else {
    iVar1 = FUN_005d2a00(0x1c,&local_4);
    if (((iVar1 == 0) && ((local_4 & 0x20) != 0)) && ((local_4 & 0x4000) != 0)) {
      _DAT_00ee9b04 = 0x1c;
      pcVar5 = "DXGI_FORMAT_R8G8B8A8_UNORM";
      goto LAB_005c2302;
    }
    FUN_0056ba10(&DAT_007fe1a0);
    _DAT_00ee9b04 = 0;
  }
  iVar1 = FUN_005d2a00(0x23,&local_4);
  if (((iVar1 == 0) && ((local_4 & 0x20) != 0)) && ((local_4 & 0x4000) != 0)) {
    _DAT_00ee9b08 = 0x23;
    pcVar5 = "DXGI_FORMAT_R16G16_UNORM";
LAB_005c234d:
    FUN_0056bc00(&DAT_007fb2f0,pcVar5);
  }
  else {
    iVar1 = FUN_005d2a00(0xb,&local_4);
    if (((iVar1 == 0) && ((local_4 & 0x20) != 0)) && ((local_4 & 0x4000) != 0)) {
      _DAT_00ee9b08 = 0xb;
      pcVar5 = "DXGI_FORMAT_R16G16B16A16_UNORM";
      goto LAB_005c234d;
    }
    FUN_0056ba10(&DAT_007fe148);
    _DAT_00ee9b08 = 0;
  }
  iVar1 = FUN_005d2a00(0x22,&local_4);
  if (((iVar1 == 0) && ((local_4 & 0x20) != 0)) && ((local_4 & 0x4000) != 0)) {
    _DAT_00ee9b0c = 0x22;
    pcVar5 = "DXGI_FORMAT_R16G16_FLOAT";
LAB_005c2398:
    FUN_0056bc00(&DAT_007fb2a8,pcVar5);
  }
  else {
    iVar1 = FUN_005d2a00(10,&local_4);
    if (((iVar1 == 0) && ((local_4 & 0x20) != 0)) && ((local_4 & 0x4000) != 0)) {
      _DAT_00ee9b0c = 10;
      pcVar5 = "DXGI_FORMAT_R16G16B16A16_FLOAT";
      goto LAB_005c2398;
    }
    iVar1 = FUN_005d2a00(2,&local_4);
    if (((iVar1 == 0) && ((local_4 & 0x20) != 0)) && ((local_4 & 0x4000) != 0)) {
      _DAT_00ee9b0c = 2;
      pcVar5 = "DXGI_FORMAT_R32G32B32A32_FLOAT";
      goto LAB_005c2398;
    }
    FUN_0056ba10(&DAT_007fe0f0);
    _DAT_00ee9b0c = 0;
  }
  iVar1 = FUN_005d2a00(0x10,&local_4);
  if (((iVar1 == 0) && ((local_4 & 0x20) != 0)) && ((local_4 & 0x4000) != 0)) {
    _DAT_00ee9b10 = 0x10;
    pcVar5 = "DXGI_FORMAT_R32G32_FLOAT";
  }
  else {
    iVar1 = FUN_005d2a00(2,&local_4);
    if (((iVar1 == 0) && ((local_4 & 0x20) != 0)) && ((local_4 & 0x4000) != 0)) {
      _DAT_00ee9b10 = 2;
      pcVar5 = "DXGI_FORMAT_R32G32B32A32_FLOAT";
    }
    else {
      iVar1 = FUN_005d2a00(10,&local_4);
      if (((iVar1 != 0) || ((local_4 & 0x20) == 0)) || ((local_4 & 0x4000) == 0)) {
        FUN_0056ba10(&DAT_007fe098);
        _DAT_00ee9b10 = 0;
        goto LAB_005c23f1;
      }
      _DAT_00ee9b10 = 10;
      pcVar5 = "DXGI_FORMAT_R16G16B16A16_FLOAT";
    }
  }
  FUN_0056bc00(&DAT_007fb260,pcVar5);
LAB_005c23f1:
  if (DAT_00a37e70 == 0x20) {
    DAT_00ee9b14 = DAT_00ee9ae0;
  }
  else {
    DAT_00ee9b14 = DAT_00ee9adc;
  }
  DAT_00ee9b18 = 0x3d;
  if (DAT_00ee9a3c < 0xa001) {
    if (DAT_00ee9a3c == 0xa000) {
      pcVar5 = "D3D_FEATURE_LEVEL_10_0";
    }
    else if (DAT_00ee9a3c == 0x9100) {
      pcVar5 = "D3D_FEATURE_LEVEL_9_1";
    }
    else if (DAT_00ee9a3c == 0x9200) {
      pcVar5 = "D3D_FEATURE_LEVEL_9_2";
    }
    else if (DAT_00ee9a3c == 0x9300) {
      pcVar5 = "D3D_FEATURE_LEVEL_9_3";
    }
  }
  else if (DAT_00ee9a3c == 0xa100) {
    pcVar5 = "D3D_FEATURE_LEVEL_10_1";
  }
  else if (DAT_00ee9a3c == 0xb000) {
    pcVar5 = "D3D_FEATURE_LEVEL_11_0";
  }
  else if (DAT_00ee9a3c == 0xb100) {
    pcVar5 = "D3D_FEATURE_LEVEL_11_1";
  }
  FUN_0056bc00(&DAT_007fdfd8,pcVar5);
  FUN_0056bc00(&DAT_007fa660,DAT_00a37da8);
  FUN_0056bc00(&DAT_007fa63c,DAT_00a37db8,DAT_00a37dbc);
  FUN_005b85a0(0x1c);
  return 0;
}

