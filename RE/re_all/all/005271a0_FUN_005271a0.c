
undefined4
FUN_005271a0(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,undefined4 param_6,
            undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  bool bVar1;
  int iVar2;
  undefined1 *puVar3;
  int local_890;
  int local_88c;
  int local_888;
  int local_884;
  undefined1 local_880 [1064];
  undefined4 local_458;
  undefined4 local_454;
  undefined1 local_440 [1088];
  
  bVar1 = false;
  if (((((param_1 < param_3) && (param_2 < param_4)) && (-1 < param_1)) &&
      ((-1 < param_2 && (param_3 <= DAT_00a381b4)))) && (param_4 <= DAT_00a381b8)) {
    local_890 = param_1;
    local_88c = param_2;
    local_888 = param_3;
    local_884 = param_4;
    iVar2 = FUN_005229c0(&local_890,local_880,0xffffffff,0xffffffff,0xffffffff,1,0);
    if (-1 < iVar2) {
      FUN_0056d380(local_440,0,0x440);
      if ((DAT_00a37d98 == 0) || ((DAT_00a38120 != -2 && (DAT_00a38120 != -4)))) {
        puVar3 = local_880;
      }
      else {
        bVar1 = true;
        FUN_00541fe0(local_458,local_454,local_880,local_440);
        FUN_0054ecc0(0,0,local_880,local_440);
        FUN_005422c0(local_440);
        puVar3 = local_440;
      }
      switch(param_6) {
      case 0:
        FUN_0054e0d0(param_5,puVar3);
        break;
      case 1:
        FUN_00540db0(param_5,puVar3,param_7,param_8);
        break;
      case 2:
        FUN_00540dd0(param_5,puVar3,param_9);
        break;
      case 3:
        FUN_005409e0(param_5,puVar3,0,1);
      }
      FUN_00517420();
      if (bVar1) {
        FUN_005421c0(local_440);
      }
      return 0;
    }
  }
  return 0xffffffff;
}

