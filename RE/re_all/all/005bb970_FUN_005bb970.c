
undefined4 FUN_005bb970(int param_1,int param_2)

{
  undefined4 local_4;
  
  if (((DAT_00f13704 != param_1) || (DAT_00f13708 != param_2)) || (DAT_00ef7324 != 0)) {
    if (DAT_00f3a070 == 0) {
      return 0xffffffff;
    }
    if (param_1 != 0) {
      local_4 = 0;
      FUN_005d2c80(0,1,&param_1,&param_2,&local_4);
    }
    DAT_00f13708 = param_2;
    DAT_00f13704 = param_1;
  }
  return 0;
}

