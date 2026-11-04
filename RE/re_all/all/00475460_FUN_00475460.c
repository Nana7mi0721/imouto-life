
void __thiscall FUN_00475460(int param_1,uint param_2)

{
  double dVar1;
  double dVar2;
  uint local_28;
  tagPOINT local_20;
  HWND local_18;
  RECT local_14;
  
  if (param_2 != 0xffffffff) {
    if ((int)(((int)param_2 < 0) - 1 & param_2) < 2) {
      local_28 = ((int)param_2 < 0) - 1 & param_2;
    }
    else {
      local_28 = 1;
    }
    *(uint *)(param_1 + 0x3bc) = local_28;
  }
  if (((DAT_00a117b4 == 0) || (*(int *)(param_1 + 0x3bc) == 0)) || (*(int *)(param_1 + 0x3c0) == 0))
  {
    ClipCursor((RECT *)0x0);
  }
  else {
    local_20.x = 0;
    local_20.y = 0;
    local_18 = (HWND)FUN_0050e7c0();
    ClientToScreen(local_18,&local_20);
    local_14.top = local_20.y;
    local_14.left = local_20.x;
    dVar2 = (double)local_20.y;
    dVar1 = (double)DAT_0084b234;
    FUN_0050e8d0(0,0);
    local_14.bottom = FUN_004fe844();
    FUN_0050e8d0(0,0,(double)DAT_0084b230,(double)local_20.x,dVar1,dVar2);
    local_14.right = FUN_004fe844();
    ClipCursor(&local_14);
  }
  return;
}

