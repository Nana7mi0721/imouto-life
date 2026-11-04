
void FUN_005eaef0(void)

{
  int local_4;
  
  local_4 = 0;
  if (DAT_00dda458 < 0) {
    FUN_00582be0();
    if (DAT_00dda458 < 0) {
      FUN_00582be0();
    }
  }
  local_4 = FUN_00519300(DAT_00dda458,0);
  if (local_4 == 0) {
    FUN_005bba30(0,1,&local_4);
    return;
  }
  local_4 = *(int *)(**(int **)(local_4 + 0x100) + 8);
  FUN_005bba30(0,1,&local_4);
  return;
}

