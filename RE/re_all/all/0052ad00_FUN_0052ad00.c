
uint FUN_0052ad00(void)

{
  int *piVar1;
  undefined1 local_128 [172];
  undefined4 local_7c [31];
  
  if ((int)DAT_00a37f8c < 1) {
    FUN_00524a70(local_128);
    FUN_005194a0(local_7c,0x10,1,0);
    local_7c[0] = 0xff00ff;
    DAT_00a37f8c = FUN_00529c50(local_128,0,DAT_00a37f8c,&DAT_0084c6d0,0x54,0,0,1,0,0);
    FUN_00580830(DAT_00a37f8c,&DAT_00a37f8c);
    if ((((DAT_00cc47d0 != 0) && (-1 < (int)DAT_00a37f8c)) &&
        ((DAT_00a37f8c & 0x7c000000) == DAT_00cc47f8)) &&
       ((((int)(DAT_00a37f8c & 0xffff) < DAT_00cc4800 &&
         (piVar1 = *(int **)(DAT_00cc47d4 + (DAT_00a37f8c & 0xffff) * 4), piVar1 != (int *)0x0)) &&
        (*piVar1 * 0x10000 == (DAT_00a37f8c & 0x3ff0000))))) {
      piVar1[0x21] = 1;
    }
  }
  return DAT_00a37f8c;
}

