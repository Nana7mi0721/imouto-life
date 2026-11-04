
void FUN_006720f0(int param_1,int *param_2,int param_3,int param_4,undefined1 param_5,
                 undefined1 param_6,undefined1 param_7,undefined1 param_8,undefined1 param_9)

{
  byte bVar1;
  
  if ((param_1 != 0) && (param_2 != (int *)0x0)) {
    *(undefined1 *)((int)param_2 + 0x1a) = param_8;
    param_2[1] = param_4;
    *(undefined1 *)((int)param_2 + 0x19) = param_6;
    *(undefined1 *)(param_2 + 6) = param_5;
    *(undefined1 *)((int)param_2 + 0x1b) = param_9;
    *param_2 = param_3;
    *(undefined1 *)(param_2 + 7) = param_7;
    FUN_0066ad80(param_1,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    bVar1 = *(byte *)((int)param_2 + 0x19);
    if ((bVar1 == 3) || ((bVar1 & 2) == 0)) {
      *(undefined1 *)((int)param_2 + 0x1d) = 1;
    }
    else {
      *(undefined1 *)((int)param_2 + 0x1d) = 3;
    }
    if ((bVar1 & 4) != 0) {
      *(char *)((int)param_2 + 0x1d) = *(char *)((int)param_2 + 0x1d) + '\x01';
    }
    bVar1 = (char)param_2[6] * *(char *)((int)param_2 + 0x1d);
    *(byte *)((int)param_2 + 0x1e) = bVar1;
    if (7 < bVar1) {
      param_2[3] = (uint)(bVar1 >> 3) * param_3;
      return;
    }
    param_2[3] = (uint)bVar1 * param_3 + 7 >> 3;
  }
  return;
}

