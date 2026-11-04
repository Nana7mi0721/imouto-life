
undefined4 FUN_0041a4a0(char *param_1)

{
  FILE *pFVar1;
  undefined4 uVar2;
  
  pFVar1 = _fopen("Game_ErrorLog.txt","at");
  if (pFVar1 == (FILE *)0x0) {
    FUN_0041a480();
    pFVar1 = _fopen("Game_ErrorLog.txt","wt");
    _fclose(pFVar1);
    pFVar1 = _fopen("Game_ErrorLog.txt","at");
    if (pFVar1 != (FILE *)0x0) {
      _fputs(param_1,pFVar1);
      _fputs("\r\n",pFVar1);
      _fclose(pFVar1);
    }
    uVar2 = 0;
  }
  else {
    _fputs(param_1,pFVar1);
    _fputs("\r\n",pFVar1);
    _fclose(pFVar1);
    uVar2 = 1;
  }
  return uVar2;
}

