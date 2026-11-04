
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0052bfa0(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  int local_110;
  int local_10c;
  int local_108;
  int local_104;
  undefined1 local_100 [256];
  
  local_128 = 0;
  local_130 = 0;
  local_11c = 0;
  local_118 = 0;
  local_124 = 0;
  local_114 = 0;
  local_120 = 0;
  local_12c = 0;
  local_110 = 0;
  DAT_00a37ee8 = 1;
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  iVar2 = DAT_00a37d70;
  if (param_1 == -1) {
    param_1 = DAT_00a37e60;
  }
  if (param_2 == -1) {
    param_2 = DAT_00a37e64;
  }
  if (param_3 == -1) {
    param_3 = DAT_00a37e70;
  }
  if (param_5 == -1) {
    param_5 = DAT_00a37e74;
  }
  if ((((param_1 == DAT_00a37e60) && (param_2 == DAT_00a37e64)) && (param_3 == DAT_00a37e70)) &&
     ((param_4 == 0 && (param_5 == DAT_00a37e74)))) {
    DAT_00a37ee8 = 0;
    return local_128;
  }
  FUN_0056bb10(&DAT_007d5a1c);
  FUN_0056bfd0();
  if (iVar2 != 0) {
    uVar1 = FUN_00530d70();
    iVar2 = FUN_00536e40(uVar1);
    if (iVar2 != 0) {
      FUN_00536d30(local_100,&local_130,&local_11c,0xfffffffe,&local_118,&local_124,&local_114,
                   &local_120);
      local_12c = FUN_00536f20(0xfffffffe);
      local_110 = 1;
    }
  }
  iVar2 = DAT_00a37e64;
  local_10c = DAT_00a37e60;
  local_104 = DAT_00a37e70;
  local_108 = DAT_00a37e74;
  if ((DAT_00a49734 == 0) && (DAT_00a49730 == 0)) {
    DAT_00a37ee8 = 0;
    return local_128;
  }
  if (DAT_00a37d80 != 0) {
    iVar2 = FUN_0050e7d0();
    if (iVar2 == 1) {
      iVar2 = (-(uint)(DAT_00a37eec != 0) & _DAT_00a37ef0) * 0x130 + DAT_00a37ef8;
      if (*(int *)(iVar2 + 0x10) < param_1) {
        DAT_00a37ee8 = 0;
        return local_128;
      }
      if (*(int *)(iVar2 + 0x14) < param_2) {
        DAT_00a37ee8 = 0;
        return local_128;
      }
    }
    FUN_00567a50(1,param_1,param_2,param_3,param_5);
    if (DAT_00a4973c == 0) {
      FUN_005e2310();
    }
    if (DAT_00a37d78 == 0) {
      FUN_005152b0();
      FUN_00515170();
    }
    iVar2 = FUN_0050e7d0();
    if (iVar2 == 1) {
      FUN_00511210(1);
    }
    FUN_0056bfe0();
    FUN_0056bb10(&DAT_007d59f0);
    goto LAB_0052c583;
  }
  if (DAT_00a37da0 != 0) {
    FUN_00580eb0(1,&LAB_00515790);
    FUN_00580eb0(0x12,0);
    FUN_005689e0();
    FUN_00536610();
    FUN_0057ab30();
    FUN_00583000();
    FUN_00594c60();
    FUN_00580eb0(0xf,0);
    FUN_00580eb0(0x10,0);
    if ((DAT_00a37d70 != 0) && (FUN_00580eb0(0x13,0), DAT_00a37d70 != 0)) {
      FUN_00580eb0(0xc,0);
    }
    FUN_00516ed0();
    FUN_00567a50(1,param_1,param_2,param_3,param_5);
    if (DAT_00a4973c == 0) {
      FUN_005e2310();
    }
    if (DAT_00a37d78 == 0) {
      FUN_005152b0();
      FUN_00515170();
    }
    FUN_0052a4a0(0xfffffffc);
    FUN_005217e0(0,0,param_1,param_2);
    FUN_005160d0(0,0xff);
    if (((DAT_00a38116 != -1) || (DAT_00a38115 != -1)) || (DAT_00a38114 != -1)) {
      _DAT_00a38114 = CONCAT13(DAT_00a38116_1,0xff0000);
      _DAT_00a38114 = CONCAT22(_DAT_00a38116,0xffff);
      if (DAT_00a37d78 == 0) {
        FUN_00581200(_DAT_00a38114);
      }
      else {
        FUN_00567b70(0xff,0xff,0xff);
      }
    }
    if (DAT_00a380bc != 0) {
      DAT_00a380bc = 0;
      DAT_00a3d360 = 1;
      if (DAT_00a37d78 != 0) {
        FUN_00567b90(0);
      }
    }
    FUN_005217b0(0xffffffff,0);
    FUN_0056bfe0();
    FUN_0056bb10(&DAT_007d59f0);
    goto LAB_0052c583;
  }
  if (DAT_00a37d70 != 0) {
    FUN_005222f0();
  }
  FUN_005173e0(param_1,param_2);
  DAT_00a37e80 = DAT_00a37e7c;
  DAT_00a37e70 = param_3;
  DAT_00a37e74 = param_5;
  FUN_005811a0(param_3 == 0x20);
  if (local_110 == 1) {
    FUN_005366a0(local_100,local_130,local_11c,local_118,local_124,local_114,local_120);
    FUN_00536980(local_12c);
  }
  iVar3 = FUN_0052be20();
  if (iVar3 == -1) {
    if ((DAT_00a37e60 == 0x140) && (DAT_00a37e64 == 0xf0)) {
      DAT_00a37e60 = 0x280;
      DAT_00a37e64 = 0x1e0;
      DAT_00a37e68 = 0x280;
      DAT_00a37e6c = 0x1e0;
      FUN_00584ed0(0x280,0x1e0);
      FUN_00522000(1);
      iVar3 = FUN_0052be20();
      if (iVar3 != -1) goto LAB_0052c4d7;
    }
    FUN_005173e0(local_10c,iVar2);
    DAT_00a37e70 = local_104;
    DAT_00a37e74 = local_108;
    FUN_005811a0(local_104 == 0x20);
    iVar2 = FUN_0052be20();
    if (iVar2 == -1) {
      DAT_00a37e60 = 0x280;
      DAT_00a37e64 = 0x1e0;
      DAT_00a37e68 = 0x280;
      DAT_00a37e6c = 0x1e0;
      FUN_00584ed0(0x280,0x1e0);
      DAT_00a37e70 = 0x10;
      DAT_00a37e74 = 0;
      FUN_005811a0(0);
      iVar2 = FUN_0052be20();
      if (iVar2 == -1) {
        DAT_00a37e60 = 0x280;
        DAT_00a37e64 = 0x1e0;
        DAT_00a37e68 = 0x280;
        DAT_00a37e6c = 0x1e0;
        FUN_00584ed0(0x280,0x1e0);
        DAT_00a37e70 = 0x20;
        DAT_00a37e74 = 0;
        FUN_005811a0(0);
        iVar2 = FUN_0052be20();
        if (iVar2 == -1) {
          local_128 = 0xffffffff;
          FUN_0056bb10(&DAT_007d59c0);
          DAT_00a37ee8 = 0;
          return local_128;
        }
      }
    }
  }
LAB_0052c4d7:
  iVar2 = FUN_0050e7d0();
  if (iVar2 == 1) {
    FUN_00511210(1);
  }
  FUN_0056bfe0();
  FUN_0056bb10(&DAT_007d59f0);
  FUN_005501a0();
  FUN_0052aa40(0,DAT_00a38120,DAT_00a38140,DAT_00a38160);
  iVar2 = 1;
  if (1 < DAT_00a37da8) {
    do {
      if ((-1 < iVar2) && (iVar2 < DAT_00a37da8)) {
        if (iVar2 == 0) {
          FUN_0052a4a0(0xffffffff);
        }
        else if (DAT_00a37d78 != 0) {
          (&DAT_00a38120)[iVar2] = 0xffffffff;
          (&DAT_00a38140)[iVar2] = 0;
          (&DAT_00a38160)[iVar2] = 0;
          FUN_00567d60();
          FUN_00567b50(iVar2,0xffffffff,0,0);
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_00a37da8);
  }
LAB_0052c583:
  FUN_0050ec50();
  DAT_00a37ee8 = 0;
  return local_128;
}

