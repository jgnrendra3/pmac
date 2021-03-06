
#ifndef _PP_PROJ_H_
#define _PP_PROJ_H_
//***********************************************************************************
// C header for accessing PMAC Global, CSGlobal, Ptr vars
// _PPScriptMode_ for Pmac Script like access global & csglobal
// global Mypvar - access with "Mypvar"
// global Myparray(32) - access with "Myparray(i)"
// csglobal Myqvar - access with "Myqvar(i)" where "i" is Coord #
// csglobal Myqarray(16) - access with "Myqvar(i,j)" where "j" is index
// _EnumMode_ for Pmac enum data type checking on Set & Get global functions
// Example
// global Mypvar
// csglobal Myqvar
// "SetGlobalVar(Myqvar, data)" will give a compile error because its a csglobal var.
// "SetCSGlobalVar(Mypvar, data)" will give a compile error because its a global var.
//************************************************************************************

#ifdef _PPScriptMode_
enum globalP {_globalP_=-1};
enum globalParray {_globalParray_=-1};
enum csglobalQ {_csglobalQ_=-1};
enum csglobalQarray {_csglobalQarray_=-1};

enum ptrM {_ptrM_=-1
,TrajStatus=4034
,AbortTrigger=4035
,Axes=4036
,BufferLength=4037
,TotalPoints=4038
,CurrentIndex=4039
,CurrentBuffer=4040
,BufferAdr_A=4041
,BufferAdr_B=4042
,CurrentBufferAdr=4043
,BufferFill_A=4044
,BufferFill_B=4045
,CurrentBufferFill=4046
,PrevBufferFill=4047
,Error=4048
,Version=4049};
enum ptrMarray {_ptrMarray_=-1};
#define	Next_Time(i)	pshm->P[(8192+i)%MAX_P]
#define	Next_A(i)	pshm->P[(12192+i)%MAX_P]
#define	Next_B(i)	pshm->P[(16192+i)%MAX_P]
#define	Next_C(i)	pshm->P[(20192+i)%MAX_P]
#define	Next_U(i)	pshm->P[(24192+i)%MAX_P]
#define	Next_V(i)	pshm->P[(28192+i)%MAX_P]
#define	Next_W(i)	pshm->P[(32192+i)%MAX_P]
#define	Next_X(i)	pshm->P[(36192+i)%MAX_P]
#define	Next_Y(i)	pshm->P[(40192+i)%MAX_P]
#define	Next_Z(i)	pshm->P[(44192+i)%MAX_P]
#define	Next_User(i)	pshm->P[(48192+i)%MAX_P]
#define	NextVelMode(i)	pshm->P[(52192+i)%MAX_P]
#define	AxesParser	pshm->P[56192]
#define	A_Axis	pshm->P[56193]
#define	B_Axis	pshm->P[56194]
#define	C_Axis	pshm->P[56195]
#define	U_Axis	pshm->P[56196]
#define	V_Axis	pshm->P[56197]
#define	W_Axis	pshm->P[56198]
#define	X_Axis	pshm->P[56199]
#define	Y_Axis	pshm->P[56200]
#define	Z_Axis	pshm->P[56201]
#define	Prev_A	pshm->P[56202]
#define	Prev_B	pshm->P[56203]
#define	Prev_C	pshm->P[56204]
#define	Prev_U	pshm->P[56205]
#define	Prev_V	pshm->P[56206]
#define	Prev_W	pshm->P[56207]
#define	Prev_X	pshm->P[56208]
#define	Prev_Y	pshm->P[56209]
#define	Prev_Z	pshm->P[56210]
#define	Time	pshm->P[56211]
#define	Current_A(i)	pshm->Coord[i%MAX_COORDS].Q[71]
#define	Current_B(i)	pshm->Coord[i%MAX_COORDS].Q[72]
#define	Current_C(i)	pshm->Coord[i%MAX_COORDS].Q[73]
#define	Current_U(i)	pshm->Coord[i%MAX_COORDS].Q[74]
#define	Current_V(i)	pshm->Coord[i%MAX_COORDS].Q[75]
#define	Current_W(i)	pshm->Coord[i%MAX_COORDS].Q[76]
#define	Current_X(i)	pshm->Coord[i%MAX_COORDS].Q[77]
#define	Current_Y(i)	pshm->Coord[i%MAX_COORDS].Q[78]
#define	Current_Z(i)	pshm->Coord[i%MAX_COORDS].Q[79]
#define	UserFunc	pshm->P[56212]
#define	VelMode	pshm->P[56213]
#define	A_Vel	pshm->P[56214]
#define	B_Vel	pshm->P[56215]
#define	C_Vel	pshm->P[56216]
#define	U_Vel	pshm->P[56217]
#define	V_Vel	pshm->P[56218]
#define	W_Vel	pshm->P[56219]
#define	X_Vel	pshm->P[56220]
#define	Y_Vel	pshm->P[56221]
#define	Z_Vel	pshm->P[56222]
#define	CalculatedBase	pshm->P[56223]
#define	TmpTime	pshm->P[56224]
#ifndef _PP_PROJ_HDR_
  void SetEnumGlobalVar(enum globalP var, double data)
  {
    pshm->P[var] = data;
  }

  double GetEnumGlobalVar(enum globalP var)
  {
    return pshm->P[var];
  }

  void SetEnumGlobalArrayVar(enum globalParray var, unsigned index, double data)
  {
    pshm->P[(var + index)%MAX_P] = data;
  }

  double GetEnumGlobalArrayVar(enum globalParray var, unsigned index)
  {
    return pshm->P[(var + index)%MAX_P];
  }

  void SetEnumCSGlobalVar(enum csglobalQ var, unsigned cs, double data)
  {
    pshm->Coord[cs % MAX_COORDS].Q[var] = data;
  }

  double GetEnumCSGlobalVar(enum csglobalQ var, unsigned cs)
  {
    return pshm->Coord[cs % MAX_COORDS].Q[var];
  }

  void SetEnumCSGlobalArrayVar(enum csglobalQarray var, unsigned index, unsigned cs, double data)
  {
    pshm->Coord[cs % MAX_COORDS].Q[(var + index)%MAX_Q] = data;
  }

  double GetEnumCSGlobalArrayVar(enum csglobalQarray var, unsigned index, unsigned cs)
  {
    return pshm->Coord[cs % MAX_COORDS].Q[(var + index)%MAX_Q];
  }

  void SetEnumPtrVar(enum ptrM var, double data)
  {
    im_write(pshm->Mdef + var, data, &pshm->Ldata);
  }

  double GetEnumPtrVar(enum ptrM var)
  {
    return im_read(pshm->Mdef + var, &pshm->Ldata);
  }

  void SetEnumPtrArrayVar(enum ptrMarray var, unsigned index, double data)
  {
    im_write(pshm->Mdef + ((var + index)%MAX_M), data, &pshm->Ldata);
  }

  double GetEnumPtrArrayVar(enum ptrMarray var, unsigned index)
  {
    return im_read(pshm->Mdef + ((var + index)%MAX_M), &pshm->Ldata);
  }

  #define SetGlobalVar(i, x)              SetEnumGlobalVar(i, x)
  #define SetGlobalArrayVar(i, j, x)      SetEnumGlobalArrayVar(i, j, x)
  #define GetGlobalVar(i)                 GetEnumGlobalVar(i)
  #define GetGlobalArrayVar(i, j)         GetEnumGlobalArrayVar(i, j)

  #define SetCSGlobalVar(i, j, x)         SetEnumCSGlobalVar(i, j, x)
  #define SetCSGlobalArrayVar(i, j, k, x) SetEnumCSGlobalArrayVar(i, j, k, x)
  #define GetCSGlobalVar(i, j)            GetEnumCSGlobalVar(i, j)
  #define GetCSGlobalArrayVar(i, j, k)    GetEnumCSGlobalArrayVar(i, j, k)

  #define SetPtrVar(i, x)                 SetEnumPtrVar(i, x)
  #define SetPtrArrayVar(i, j, x)         SetEnumPtrArrayVar(i, j, x)
  #define GetPtrVar(i)                    GetEnumPtrVar(i)
  #define GetPtrArrayVar(i, j)            GetEnumPtrArrayVar(i, j)

#else

  void SetEnumGlobalVar(enum globalP var, double data);
  double GetEnumGlobalVar(enum globalP var);
  void SetEnumGlobalArrayVar(enum globalParray var, unsigned index, double data);
  double GetEnumGlobalArrayVar(enum globalParray var, unsigned index);
  void SetEnumCSGlobalVar(enum csglobalQ var, unsigned cs, double data);
  double GetEnumCSGlobalVar(enum csglobalQ var, unsigned cs);
  void SetEnumCSGlobalArrayVar(enum csglobalQarray var, unsigned index, unsigned cs, double data);
  double GetEnumCSGlobalArrayVar(enum csglobalQarray var, unsigned index, unsigned cs);
  void SetEnumPtrVar(enum ptrM var, double data);
  double GetEnumPtrVar(enum ptrM var);
  void SetEnumPtrArrayVar(enum ptrMarray var, unsigned index, double data);
  double GetEnumPtrArrayVar(enum ptrMarray var, unsigned index);

  #define SetGlobalVar(i, x)              SetEnumGlobalVar(i, x)
  #define SetGlobalArrayVar(i, j, x)      SetEnumGlobalArrayVar(i, j, x)
  #define GetGlobalVar(i)                 GetEnumGlobalVar(i)
  #define GetGlobalArrayVar(i, j)         GetEnumGlobalArrayVar(i, j)

  #define SetCSGlobalVar(i, j, x)         SetEnumCSGlobalVar(i, j, x)
  #define SetCSGlobalArrayVar(i, j, k, x) SetEnumCSGlobalArrayVar(i, j, k, x)
  #define GetCSGlobalVar(i, j)            GetEnumCSGlobalVar(i, j)
  #define GetCSGlobalArrayVar(i, j, k)    GetEnumCSGlobalArrayVar(i, j, k)

  #define SetPtrVar(i, x)                 SetEnumPtrVar(i, x)
  #define SetPtrArrayVar(i, j, x)         SetEnumPtrArrayVar(i, j, x)
  #define GetPtrVar(i)                    GetEnumPtrVar(i)
  #define GetPtrArrayVar(i, j)            GetEnumPtrArrayVar(i, j)

#endif
// end of #ifdef _PPScriptMode_
#else
#ifdef _EnumMode_
enum globalP {_globalP_=-1
,AxesParser=56192
,A_Axis=56193
,B_Axis=56194
,C_Axis=56195
,U_Axis=56196
,V_Axis=56197
,W_Axis=56198
,X_Axis=56199
,Y_Axis=56200
,Z_Axis=56201
,Prev_A=56202
,Prev_B=56203
,Prev_C=56204
,Prev_U=56205
,Prev_V=56206
,Prev_W=56207
,Prev_X=56208
,Prev_Y=56209
,Prev_Z=56210
,Time=56211
,UserFunc=56212
,VelMode=56213
,A_Vel=56214
,B_Vel=56215
,C_Vel=56216
,U_Vel=56217
,V_Vel=56218
,W_Vel=56219
,X_Vel=56220
,Y_Vel=56221
,Z_Vel=56222
,CalculatedBase=56223
,TmpTime=56224};
enum globalParray {_globalParray_=-1
,Next_Time=8192
,Next_A=12192
,Next_B=16192
,Next_C=20192
,Next_U=24192
,Next_V=28192
,Next_W=32192
,Next_X=36192
,Next_Y=40192
,Next_Z=44192
,Next_User=48192
,NextVelMode=52192};
enum csglobalQ {_csglobalQ_=-1
,Current_A=71
,Current_B=72
,Current_C=73
,Current_U=74
,Current_V=75
,Current_W=76
,Current_X=77
,Current_Y=78
,Current_Z=79};
enum csglobalQarray {_csglobalQarray_=-1};
enum ptrM {_ptrM_=-1
,TrajStatus=4034
,AbortTrigger=4035
,Axes=4036
,BufferLength=4037
,TotalPoints=4038
,CurrentIndex=4039
,CurrentBuffer=4040
,BufferAdr_A=4041
,BufferAdr_B=4042
,CurrentBufferAdr=4043
,BufferFill_A=4044
,BufferFill_B=4045
,CurrentBufferFill=4046
,PrevBufferFill=4047
,Error=4048
,Version=4049};
enum ptrMarray {_ptrMarray_=-1};
#ifndef _PP_PROJ_HDR_
  void SetEnumGlobalVar(enum globalP var, double data)
  {
    pshm->P[var] = data;
  }

  double GetEnumGlobalVar(enum globalP var)
  {
    return pshm->P[var];
  }

  void SetEnumGlobalArrayVar(enum globalParray var, unsigned index, double data)
  {
    pshm->P[(var + index)%MAX_P] = data;
  }

  double GetEnumGlobalArrayVar(enum globalParray var, unsigned index)
  {
    return pshm->P[(var + index)%MAX_P];
  }

  void SetEnumCSGlobalVar(enum csglobalQ var, unsigned cs, double data)
  {
    pshm->Coord[cs % MAX_COORDS].Q[var] = data;
  }

  double GetEnumCSGlobalVar(enum csglobalQ var, unsigned cs)
  {
    return pshm->Coord[cs % MAX_COORDS].Q[var];
  }

  void SetEnumCSGlobalArrayVar(enum csglobalQarray var, unsigned index, unsigned cs, double data)
  {
    pshm->Coord[cs % MAX_COORDS].Q[(var + index)%MAX_Q] = data;
  }

  double GetEnumCSGlobalArrayVar(enum csglobalQarray var, unsigned index, unsigned cs)
  {
    return pshm->Coord[cs % MAX_COORDS].Q[(var + index)%MAX_Q];
  }

  void SetEnumPtrVar(enum ptrM var, double data)
  {
    im_write(pshm->Mdef + var, data, &pshm->Ldata);
  }

  double GetEnumPtrVar(enum ptrM var)
  {
    return im_read(pshm->Mdef + var, &pshm->Ldata);
  }

  void SetEnumPtrArrayVar(enum ptrMarray var, unsigned index, double data)
  {
    im_write(pshm->Mdef + ((var + index)%MAX_M), data, &pshm->Ldata);
  }

  double GetEnumPtrArrayVar(enum ptrMarray var, unsigned index)
  {
    return im_read(pshm->Mdef + ((var + index)%MAX_M), &pshm->Ldata);
  }

  #define SetGlobalVar(i, x)              SetEnumGlobalVar(i, x)
  #define SetGlobalArrayVar(i, j, x)      SetEnumGlobalArrayVar(i, j, x)
  #define GetGlobalVar(i)                 GetEnumGlobalVar(i)
  #define GetGlobalArrayVar(i, j)         GetEnumGlobalArrayVar(i, j)

  #define SetCSGlobalVar(i, j, x)         SetEnumCSGlobalVar(i, j, x)
  #define SetCSGlobalArrayVar(i, j, k, x) SetEnumCSGlobalArrayVar(i, j, k, x)
  #define GetCSGlobalVar(i, j)            GetEnumCSGlobalVar(i, j)
  #define GetCSGlobalArrayVar(i, j, k)    GetEnumCSGlobalArrayVar(i, j, k)

  #define SetPtrVar(i, x)                 SetEnumPtrVar(i, x)
  #define SetPtrArrayVar(i, j, x)         SetEnumPtrArrayVar(i, j, x)
  #define GetPtrVar(i)                    GetEnumPtrVar(i)
  #define GetPtrArrayVar(i, j)            GetEnumPtrArrayVar(i, j)

#else

  void SetEnumGlobalVar(enum globalP var, double data);
  double GetEnumGlobalVar(enum globalP var);
  void SetEnumGlobalArrayVar(enum globalParray var, unsigned index, double data);
  double GetEnumGlobalArrayVar(enum globalParray var, unsigned index);
  void SetEnumCSGlobalVar(enum csglobalQ var, unsigned cs, double data);
  double GetEnumCSGlobalVar(enum csglobalQ var, unsigned cs);
  void SetEnumCSGlobalArrayVar(enum csglobalQarray var, unsigned index, unsigned cs, double data);
  double GetEnumCSGlobalArrayVar(enum csglobalQarray var, unsigned index, unsigned cs);
  void SetEnumPtrVar(enum ptrM var, double data);
  double GetEnumPtrVar(enum ptrM var);
  void SetEnumPtrArrayVar(enum ptrMarray var, unsigned index, double data);
  double GetEnumPtrArrayVar(enum ptrMarray var, unsigned index);

  #define SetGlobalVar(i, x)              SetEnumGlobalVar(i, x)
  #define SetGlobalArrayVar(i, j, x)      SetEnumGlobalArrayVar(i, j, x)
  #define GetGlobalVar(i)                 GetEnumGlobalVar(i)
  #define GetGlobalArrayVar(i, j)         GetEnumGlobalArrayVar(i, j)

  #define SetCSGlobalVar(i, j, x)         SetEnumCSGlobalVar(i, j, x)
  #define SetCSGlobalArrayVar(i, j, k, x) SetEnumCSGlobalArrayVar(i, j, k, x)
  #define GetCSGlobalVar(i, j)            GetEnumCSGlobalVar(i, j)
  #define GetCSGlobalArrayVar(i, j, k)    GetEnumCSGlobalArrayVar(i, j, k)

  #define SetPtrVar(i, x)                 SetEnumPtrVar(i, x)
  #define SetPtrArrayVar(i, j, x)         SetEnumPtrArrayVar(i, j, x)
  #define GetPtrVar(i)                    GetEnumPtrVar(i)
  #define GetPtrArrayVar(i, j)            GetEnumPtrArrayVar(i, j)

#endif
// end of #ifdef _EnumMode_
#else
// ***** Standard default mode *****
#define Next_Time 8192
#define Next_A 12192
#define Next_B 16192
#define Next_C 20192
#define Next_U 24192
#define Next_V 28192
#define Next_W 32192
#define Next_X 36192
#define Next_Y 40192
#define Next_Z 44192
#define Next_User 48192
#define NextVelMode 52192
#define AxesParser 56192
#define A_Axis 56193
#define B_Axis 56194
#define C_Axis 56195
#define U_Axis 56196
#define V_Axis 56197
#define W_Axis 56198
#define X_Axis 56199
#define Y_Axis 56200
#define Z_Axis 56201
#define TrajStatus 4034
#define AbortTrigger 4035
#define Axes 4036
#define BufferLength 4037
#define TotalPoints 4038
#define CurrentIndex 4039
#define CurrentBuffer 4040
#define BufferAdr_A 4041
#define BufferAdr_B 4042
#define CurrentBufferAdr 4043
#define BufferFill_A 4044
#define BufferFill_B 4045
#define CurrentBufferFill 4046
#define PrevBufferFill 4047
#define Error 4048
#define Version 4049
#define Prev_A 56202
#define Prev_B 56203
#define Prev_C 56204
#define Prev_U 56205
#define Prev_V 56206
#define Prev_W 56207
#define Prev_X 56208
#define Prev_Y 56209
#define Prev_Z 56210
#define Time 56211
#define Current_A 71
#define Current_B 72
#define Current_C 73
#define Current_U 74
#define Current_V 75
#define Current_W 76
#define Current_X 77
#define Current_Y 78
#define Current_Z 79
#define UserFunc 56212
#define VelMode 56213
#define A_Vel 56214
#define B_Vel 56215
#define C_Vel 56216
#define U_Vel 56217
#define V_Vel 56218
#define W_Vel 56219
#define X_Vel 56220
#define Y_Vel 56221
#define Z_Vel 56222
#define CalculatedBase 56223
#define TmpTime 56224
#endif
#endif
#endif //_PP_PROJ_H_
