
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005b5de0(void)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_00586680();
  iVar3 = 0xc99;
  puVar1 = &DAT_00e39a80;
  do {
    iVar3 = iVar3 + -1;
    puVar1[-1] = 0;
    *puVar1 = 0x3f800000;
    puVar1 = puVar1 + 5;
  } while (iVar3 != 0);
  iVar3 = 0x924;
  puVar1 = &DAT_00e49680;
  do {
    iVar3 = iVar3 + -1;
    puVar1[-1] = 0;
    *puVar1 = 0x3f800000;
    puVar1 = puVar1 + 7;
  } while (iVar3 != 0);
  iVar3 = 0x666;
  puVar1 = &DAT_00e59680;
  do {
    puVar1[2] = 0xffffffff;
    puVar1[-1] = 0;
    iVar3 = iVar3 + -1;
    *puVar1 = 0x3f800000;
    puVar1 = puVar1 + 10;
  } while (iVar3 != 0);
  _DAT_00e39a68 = &DAT_00e69674;
  _DAT_00e39a6c = &DAT_00e69674;
  _DAT_00e39a5c = &DAT_00e39a74;
  DAT_00e39a60 = &DAT_00e49674;
  _DAT_00e39a64 = &DAT_00e59674;
  uVar2 = 0;
  do {
    if (*(int *)((int)&DAT_00a37fe0 + uVar2) == 0) {
      *(undefined4 *)((int)&DAT_00a37fe0 + uVar2) = 3;
    }
    if (*(int *)((int)&DAT_00a38020 + uVar2) == 0) {
      *(undefined4 *)((int)&DAT_00a38020 + uVar2) = 3;
    }
    if (*(int *)((int)&DAT_00a38060 + uVar2) == 0) {
      *(undefined4 *)((int)&DAT_00a38060 + uVar2) = 3;
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0x40);
  uVar2 = 0;
  do {
    FUN_005d3ad0(uVar2,1,(&DAT_00a37fe0)[uVar2]);
    FUN_005d3ad0(uVar2,2,(&DAT_00a38020)[uVar2]);
    FUN_005d3ad0(uVar2,3,(&DAT_00a38060)[uVar2]);
    if (DAT_00e7984c == 0) {
      (&DAT_00e80544)[uVar2] = 1;
      (&DAT_00e80584)[uVar2] = 1;
      (&DAT_00e805c4)[uVar2] = 1;
    }
    else if (DAT_00e7984c == 1) {
      (&DAT_00e80544)[uVar2] = 2;
      (&DAT_00e80584)[uVar2] = 2;
      (&DAT_00e805c4)[uVar2] = 2;
    }
    else if (DAT_00e7984c == 2) {
      (&DAT_00e80544)[uVar2] = 3;
      (&DAT_00e80584)[uVar2] = 3;
      (&DAT_00e805c4)[uVar2] = 2;
    }
    FUN_005d3ad0(uVar2,5,(&DAT_00e80544)[uVar2]);
    FUN_005d3ad0(uVar2,6,(&DAT_00e80584)[uVar2]);
    FUN_005d3ad0(uVar2,7,(&DAT_00e805c4)[uVar2]);
    (&DAT_00e80504)[uVar2] = 1;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x10);
  iVar4 = 0x101;
  iVar3 = 4;
  do {
    FUN_005d3ad0(iVar4,1,3);
    FUN_005d3ad0(iVar4,2,3);
    FUN_005d3ad0(iVar4,3,3);
    FUN_005d3ad0(iVar4,5,1);
    FUN_005d3ad0(iVar4,6,1);
    FUN_005d3ad0(iVar4,7,0);
    iVar4 = iVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  FUN_005d3a70(0x16,1);
  FUN_005d3a70(0x89,1);
  FUN_005d3a70(9,1);
  FUN_005d3a70(0x1a,0);
  FUN_005d3a70(0x1d,1);
  FUN_005d3a70(0x93,0);
  FUN_005d3a70(0x8f,1);
  FUN_005d3a70(0x1c,0);
  FUN_005d3a70(0x8c,0);
  FUN_005d3a70(0x22,0);
  FUN_005d3a70(0x24,0);
  FUN_005d3a70(0x25,0x3f800000);
  FUN_005d3a10(&local_44);
  DAT_00e804a4 = local_44;
  DAT_00e804a8 = local_40;
  DAT_00e804ac = local_3c;
  DAT_00e804b0 = local_38;
  DAT_00e804c4 = local_24;
  DAT_00e804c8 = local_20;
  DAT_00e804cc = local_1c;
  DAT_00e804d0 = local_18;
  DAT_00e804d4 = local_14;
  DAT_00e804d8 = local_10;
  DAT_00e804dc = local_c;
  DAT_00e804e0 = local_8;
  DAT_00e804b4 = local_34;
  DAT_00e804b8 = local_30;
  DAT_00e804bc = local_2c;
  DAT_00e804c0 = local_28;
  DAT_00e804e4 = local_4;
  FUN_0056d380(&DAT_00e79690,0,0x1b4);
  DAT_00e796c0 = 0;
  uVar2 = 0;
  do {
    *(undefined4 *)((int)&DAT_00e796c4 + uVar2) = 0;
    *(undefined4 *)((int)&DAT_00e796cc + uVar2) = 0;
    *(undefined2 *)((int)&DAT_00e796d0 + uVar2) = 2;
    *(undefined2 *)((int)&DAT_00e796d2 + uVar2) = 0;
    *(undefined2 *)((int)&DAT_00e796d4 + uVar2) = 1;
    *(undefined2 *)((int)&DAT_00e796d6 + uVar2) = 2;
    *(undefined2 *)((int)&DAT_00e796d8 + uVar2) = 0;
    *(undefined2 *)((int)&DAT_00e796da + uVar2) = 1;
    uVar2 = uVar2 + 0x18;
  } while (uVar2 < 0x180);
  _DAT_00e79880 = 0;
  DAT_00e804a0 = 1;
  DAT_00e80500 = 1;
  _DAT_00e79884 = 0x3f800000;
  DAT_00e80638 = 1;
  DAT_00e80b78 = 1;
  DAT_00e80b80 = 0;
  DAT_00e80b7c = 4;
  DAT_00e79848 = 0;
  DAT_00e79870 = 3;
  DAT_00e79844 = 0;
  DAT_00e80b5c = 1;
  DAT_00e79874 = 0;
  DAT_00e7987c = 0;
  DAT_00e79878 = 0;
  uVar2 = 0;
  do {
    *(undefined4 *)((int)&DAT_00e8065c + uVar2) = *(undefined4 *)((int)&DAT_00a37fe0 + uVar2);
    *(undefined4 *)((int)&DAT_00e8069c + uVar2) = *(undefined4 *)((int)&DAT_00a38020 + uVar2);
    *(undefined4 *)((int)&DAT_00e806dc + uVar2) = *(undefined4 *)((int)&DAT_00a38060 + uVar2);
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0x40);
  DAT_00e80b70 = 0;
  DAT_00e80b68 = DAT_00a37e60;
  DAT_00e80b74 = 0x3f800000;
  DAT_00e8063c = DAT_00ddb5b4;
  DAT_00e80b60 = 0;
  DAT_00e80b64 = 0;
  DAT_00e80b6c = DAT_00a37e64;
  DAT_00e7984c = 3;
  DAT_00e39a00 = 1;
  DAT_00e39a24 = 0;
  DAT_00e39a28 = 0;
  DAT_00e39a14 = 0;
  DAT_00e39a34 = 0xffffffff;
  DAT_00e39a0c = 0xffffffff;
  DAT_00e39a10 = 0;
  DAT_00e39a04 = 0;
  DAT_00e39a08 = 0;
  DAT_00e39a18 = 1;
  DAT_00e39a1c = 0;
  DAT_00e39a50 = 0;
  DAT_00e39a2c = 0;
  DAT_00e39a4c = 0;
  DAT_00e79684 = 0xffffffff;
  DAT_00e7968c = 0;
  DAT_00e79688 = 0;
  DAT_00e79678 = 0;
  DAT_00e39a58 = &DAT_00e49674;
  DAT_00e7967c = 1;
  FUN_005b5550();
  iVar3 = FUN_005d35f0();
  if ((iVar3 != 0) && (DAT_00e79688 != 1)) {
    FUN_005d3930();
    DAT_00e79688 = 1;
    DAT_00e399fc = 0;
  }
  FUN_005a7f60();
  DAT_00e79678 = 0;
  puVar1 = *(undefined4 **)(&DAT_00e39a5c + DAT_00e7967c * 4);
  DAT_00e79674 = 0;
  DAT_00e79680 = 1;
  DAT_00e39a58 = puVar1;
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  DAT_00e79678 = DAT_00e79678 + 1;
  DAT_00e39a58 = DAT_00e39a58 + 5;
  return 0;
}

