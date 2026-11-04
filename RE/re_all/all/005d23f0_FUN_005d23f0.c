
undefined4 FUN_005d23f0(void)

{
  int *piVar1;
  int iVar2;
  FARPROC pFVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_1a [2];
  int aiStack_18 [6];
  
  if (DAT_00f3a058 == (HMODULE)0x0) {
    return 0xffffffff;
  }
  iVar2 = FUN_0050e7d0();
  iVar5 = 2;
  if (iVar2 == 1) {
    FUN_0050ea10();
  }
  FUN_0056bb10(&PTR_DAT_007ff8d0);
  pFVar3 = GetProcAddress(DAT_00f3a058,"D3D11CreateDevice");
  if (pFVar3 == (FARPROC)0x0) {
    FUN_0056bb10("1YWe\n");
    return 0xffffffff;
  }
  FUN_0056bb10(&DAT_007d4974);
  FUN_0056bb10(&PTR_PTR_007ff884);
  iVar2 = (**(code **)(*DAT_00f3a068 + 0x1c))(DAT_00f3a068,0,&DAT_00f3a064);
  if (iVar2 < 0) goto LAB_005d25be;
  FUN_0056bb10(&DAT_007d4974);
  if (DAT_00ee9a40 < 1) {
    if (DAT_00ee9a44 != 0) {
      if ((DAT_00ee9a40 == 0) && (DAT_00ee9a44 != 0)) {
        DAT_00ee9a40 = 0xa000;
      }
      goto LAB_005d24ea;
    }
    FUN_0056bb10(&PTR_LAB_007ff830);
  }
  else {
LAB_005d24ea:
    FUN_0056bb10(&DAT_007ff7e0);
    iVar5 = 0;
    iVar4 = 0;
    iVar2 = DAT_00860b04;
    while (iVar2 != -1) {
      if (DAT_00ee9a40 <= iVar2) {
        *(int *)(auStack_1a + iVar5 * 4 + -0xe) = iVar2;
        iVar5 = iVar5 + 1;
      }
      piVar1 = &DAT_00860b08 + iVar4;
      iVar4 = iVar4 + 1;
      iVar2 = *piVar1;
    }
  }
  FUN_0056bb10(&PTR_PTR_007ff79c);
  iVar5 = (*pFVar3)(~-(uint)(DAT_00ee9a44 != 0) & (uint)DAT_00f3a064,-(uint)(DAT_00ee9a44 != 0) & 5,
                    0,(uint)(DAT_00aaf0e4 == 0),auStack_1a + -0xe,iVar5,7,&DAT_00f3a070,
                    &DAT_00ee9a3c,&DAT_00f3a074);
  if (iVar5 != 0) {
LAB_005d25be:
    FUN_0056bb10("1YWe\n");
    if (DAT_00f3a078 != (int *)0x0) {
      (**(code **)(*DAT_00f3a078 + 8))(DAT_00f3a078);
      DAT_00f3a078 = (int *)0x0;
    }
    if (DAT_00f3a074 != (int *)0x0) {
      (**(code **)(*DAT_00f3a074 + 8))(DAT_00f3a074);
      DAT_00f3a074 = (int *)0x0;
    }
    if (DAT_00f3a070 != (int *)0x0) {
      (**(code **)(*DAT_00f3a070 + 8))(DAT_00f3a070);
      DAT_00f3a070 = (int *)0x0;
    }
    if (DAT_00f3a064 != (int *)0x0) {
      (**(code **)(*DAT_00f3a064 + 8))(DAT_00f3a064);
      DAT_00f3a064 = (int *)0x0;
    }
    if (DAT_00f3a060 != (int *)0x0) {
      (**(code **)(*DAT_00f3a060 + 8))(DAT_00f3a060);
      DAT_00f3a060 = (int *)0x0;
    }
    return 0xffffffff;
  }
  FUN_0056bb10(&DAT_007d4974);
  if (DAT_00aaf0e4 != 0) {
    FUN_0056bb10(&PTR_PTR_007ff728);
    iVar5 = (**(code **)(*DAT_00f3a070 + 0x6c))(DAT_00f3a070,0,&DAT_00f3a078);
    if (iVar5 != 0) goto LAB_005d25be;
    FUN_0056bb10(&DAT_007d4974);
  }
  FUN_0056bb10(&PTR_PTR_007ff6f0);
  iVar5 = (**(code **)*DAT_00f3a070)(DAT_00f3a070,&DAT_0085e664,&DAT_00f3a060);
  if (iVar5 < 0) {
    FUN_0056bb10("1YWe\n");
  }
  FUN_0056bb10(&DAT_007d4974);
  if (DAT_00f3a060 != (int *)0x0) {
    (**(code **)(*DAT_00f3a060 + 0x30))(DAT_00f3a060,1);
    FUN_0056bb10(&PTR_PTR_007ff688);
  }
  return 0;
}

