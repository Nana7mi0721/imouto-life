
void FUN_0066e860(int *param_1,byte *param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  
  if (*(char *)((int)param_1 + 9) == '\x10') {
    pbVar1 = param_2 + param_1[1];
    pbVar2 = param_2;
    for (; param_2 < pbVar1; param_2 = param_2 + 2) {
      *pbVar2 = *param_2 + (char)((((uint)param_2[1] - (uint)*param_2) + 0x80) * 0xffff >> 0x18);
      pbVar2 = pbVar2 + 1;
    }
    *(undefined1 *)((int)param_1 + 9) = 8;
    *(byte *)((int)param_1 + 0xb) = *(byte *)((int)param_1 + 10) << 3;
    param_1[1] = (uint)*(byte *)((int)param_1 + 10) * *param_1;
  }
  return;
}

