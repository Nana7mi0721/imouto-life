
void FUN_0079ef00(short *param_1,int param_2,int param_3,uint param_4)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  
  pbVar2 = (byte *)((int)((int)*(short *)(param_3 + 2) * param_4) / 2 + *(int *)(param_3 + 0x14));
  if (0 < *(short *)(param_3 + 2)) {
    iVar3 = 0;
    while( true ) {
      bVar1 = *pbVar2;
      pbVar2 = pbVar2 + 1;
      param_4 = (uint)bVar1;
      iVar4 = iVar3 + 2;
      *param_1 = (ushort)(bVar1 >> 1 & 7) * 9;
      *(undefined1 *)(iVar3 + param_2) =
           *(undefined1 *)
            ((*(short *)(param_3 + 2) + -1) * (param_4 & 1) + *(int *)(param_3 + 0x10) + -2 + iVar4)
      ;
      param_1[1] = (ushort)(bVar1 >> 5) * 9;
      *(undefined1 *)(iVar3 + 1 + param_2) =
           *(undefined1 *)
            ((bVar1 >> 4 & 1) * (*(short *)(param_3 + 2) + -1) + *(int *)(param_3 + 0x10) + -1 +
            iVar4);
      if (*(short *)(param_3 + 2) <= iVar4) break;
      iVar3 = iVar4;
      param_1 = param_1 + 2;
    }
  }
  return;
}

