
void FUN_00670f30(int *param_1,byte *param_2,int param_3,int param_4)

{
  byte *pbVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  int iVar7;
  
  iVar7 = *param_1;
  if (*(char *)((int)param_1 + 9) != '\b') {
    return;
  }
  cVar2 = (char)param_1[2];
  if ((cVar2 == '\x02') && (iVar4 = iVar7, pbVar5 = param_2, param_3 != 0)) {
    for (; iVar4 != 0; iVar4 = iVar4 + -1) {
      bVar3 = *param_2;
      pbVar1 = param_2 + 1;
      pbVar6 = param_2 + 2;
      param_2 = param_2 + 3;
      *pbVar5 = *(byte *)((((bVar3 & 0xf8) << 5 | *pbVar1 & 0xf8) << 2 | (int)(uint)*pbVar6 >> 3) +
                         param_3);
      pbVar5 = pbVar5 + 1;
    }
  }
  else {
    if ((cVar2 != '\x06') || (iVar4 = iVar7, pbVar5 = param_2, param_3 == 0)) {
      if (cVar2 != '\x03') {
        return;
      }
      if (param_4 == 0) {
        return;
      }
      for (; iVar7 != 0; iVar7 = iVar7 + -1) {
        *param_2 = *(byte *)((uint)*param_2 + param_4);
        param_2 = param_2 + 1;
      }
      return;
    }
    for (; iVar4 != 0; iVar4 = iVar4 + -1) {
      bVar3 = *param_2;
      pbVar1 = param_2 + 1;
      pbVar6 = param_2 + 2;
      param_2 = param_2 + 4;
      *pbVar5 = *(byte *)((((bVar3 & 0xf8) << 5 | *pbVar1 & 0xf8) << 2 | (int)(uint)*pbVar6 >> 3) +
                         param_3);
      pbVar5 = pbVar5 + 1;
    }
  }
  bVar3 = *(byte *)((int)param_1 + 9);
  *(undefined1 *)(param_1 + 2) = 3;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *(byte *)((int)param_1 + 0xb) = bVar3;
  if (bVar3 < 8) {
    param_1[1] = (uint)bVar3 * iVar7 + 7 >> 3;
    return;
  }
  param_1[1] = (uint)(bVar3 >> 3) * iVar7;
  return;
}

