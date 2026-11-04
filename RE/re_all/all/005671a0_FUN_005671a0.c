
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005671a0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int *piStack_8;
  undefined1 auStack_4 [4];
  
  FUN_0056bb10(&DAT_007d6c58);
  uVar2 = DAT_00aa700c;
  uVar1 = DAT_00aa7004;
  FUN_0056d380(&DAT_00aa4fb8,0,0x9114);
  iVar3 = 0;
  DAT_00aa7004 = uVar1;
  DAT_00aa700c = uVar2;
  do {
    FUN_00564230(iVar3);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x17);
  if (DAT_00a2e8c8 < 0x109) goto LAB_005672d8;
  iVar3 = (*DAT_00aba190)(&DAT_0085efd4,0,1,&DAT_0085eff4,&DAT_00aae0bc);
  if (iVar3 == 0) {
    iVar3 = (**(code **)(*DAT_00aae0bc + 0x38))(DAT_00aae0bc,auStack_4,4);
    if (iVar3 < 0) goto LAB_005672aa;
    DAT_00aae0c0 = operator_new(8);
    if (DAT_00aae0c0 == (int *)0x0) {
      DAT_00aae0c0 = (int *)0x0;
    }
    else {
      *DAT_00aae0c0 = (int)DxLib::DX_UIElementSink::vftable;
      DAT_00aae0c0[1] = 1;
    }
    if (DAT_00aae0c0 != (int *)0x0) {
      iVar3 = (**(code **)*DAT_00aae0bc)(DAT_00aae0bc,&DAT_0085ef14,&piStack_8);
      if (-1 < iVar3) {
        piVar4 = &DAT_00aae0c8;
        iVar3 = (**(code **)(*piStack_8 + 0xc))(piStack_8,&DAT_0085ef34,DAT_00aae0c0);
        (**(code **)(*piVar4 + 8))(piVar4);
        piStack_8 = (int *)0x0;
        if (-1 < iVar3) goto LAB_005672d8;
      }
      goto LAB_005672aa;
    }
  }
  else {
LAB_005672aa:
    if (DAT_00aae0c0 != (int *)0x0) {
      (**(code **)(*DAT_00aae0c0 + 8))(DAT_00aae0c0);
      DAT_00aae0c0 = (int *)0x0;
    }
  }
  if (DAT_00aae0bc != (int *)0x0) {
    (**(code **)(*DAT_00aae0bc + 8))(DAT_00aae0bc);
    DAT_00aae0bc = (int *)0x0;
  }
LAB_005672d8:
  DAT_00aa84b4 = 0xffffffff;
  DAT_00aa84b0 = 0xffffffff;
  DAT_00aa84a0 = 0;
  _DAT_00aa84a4 = 0;
  DAT_00aa84a8 = 500;
  DAT_00aa84ac = 1;
  FUN_0056bb10(&DAT_007d6c48);
  return 0;
}

