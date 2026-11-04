
void FUN_005a51d0(int param_1,int param_2)

{
  undefined1 local_80 [64];
  undefined1 local_40 [64];
  
  if ((param_2 != 0) || (param_1 != 0)) {
    if (DAT_00a381c4 == 0) {
      FUN_005850a0(local_80,&DAT_00a384a0,&DAT_00a38798);
      FUN_005850a0(local_80,local_80,&DAT_00a386d8);
    }
    else {
      FUN_005850a0(local_80,&DAT_00a38248,&DAT_00a386d8);
    }
    if (DAT_00f3a04c != 0) {
      FUN_005d39b0(3,local_80);
      FUN_00585710(local_40,local_80);
      FUN_0059cb80(&DAT_00ddb600,0,0,2,local_40,4,1);
    }
  }
  return;
}

