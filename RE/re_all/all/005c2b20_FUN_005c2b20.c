
undefined4 FUN_005c2b20(int param_1,int param_2,uint param_3)

{
  int local_48;
  int local_44;
  undefined1 local_40 [4];
  undefined4 local_3c;
  int local_38;
  undefined4 local_2c;
  undefined4 local_28;
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if (7 < param_3) {
    return 0xffffffff;
  }
  if ((((&DAT_00f1370c)[param_3] != param_1) || ((&DAT_00f1388c)[param_3] != param_2)) ||
     (DAT_00ef7324 != 0)) {
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    (&DAT_00f1370c)[param_3] = param_1;
    (&DAT_00f1388c)[param_3] = param_2;
    if (param_1 == 0) {
      FUN_0056d380(&DAT_00f1372c + param_3 * 0x2c,0,0x2c);
    }
    else {
      FUN_005d2ee0(param_1,&DAT_00f1372c + param_3 * 0x2c);
    }
    FUN_005bb570();
    if ((param_3 == 0) && (param_1 != 0)) {
      FUN_005d2ee0(param_1,&local_2c);
      FUN_005d2380(param_2,local_40);
      switch(local_3c) {
      case 4:
      case 5:
        break;
      case 6:
      case 7:
        local_38 = 0;
        break;
      default:
        local_38 = local_44;
      }
      FUN_005185c0(local_2c,local_28,local_38,&local_44,&local_48);
      FUN_005c2ae0(0,0,(float)local_44,(float)local_48);
    }
  }
  return 0;
}

