
undefined4 FUN_005bb610(int *param_1,int param_2)

{
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if (((DAT_00f138ac != param_1) || (DAT_00f138dc != param_2)) || (DAT_00ef7324 != 0)) {
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    DAT_00f138ac = param_1;
    DAT_00f138dc = param_2;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x28))(param_1,&DAT_00f138b0);
      FUN_005bb570();
      return 0;
    }
    FUN_0056d380(&DAT_00f138b0,0,0x2c);
    FUN_005bb570();
  }
  return 0;
}

