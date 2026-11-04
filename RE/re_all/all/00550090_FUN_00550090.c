
undefined8 FUN_00550090(void)

{
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  LARGE_INTEGER local_18;
  undefined8 local_10 [2];
  
  if (DAT_00a238d4 != 0) {
    QueryPerformanceCounter(&local_18);
    local_20 = 1000000;
    local_1c = 0;
    FUN_0056d6c0(&local_20,&local_18,local_10);
    FUN_0056d730(local_10,&DAT_00a238d8,&local_28);
    return CONCAT44(local_24,local_28);
  }
  if (DAT_00aba154 == 0) {
    return 0xffffffffffffffff;
  }
  local_20 = 1000;
  local_1c = 0;
  local_28 = (*DAT_00aba168)();
  local_24 = 0;
  FUN_0056d6c0(&local_20,&local_28,local_10);
  return local_10[0];
}

