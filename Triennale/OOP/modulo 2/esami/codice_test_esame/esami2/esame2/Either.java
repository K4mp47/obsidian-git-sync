package esami2.esame2;

public interface Either<T> {
    T onSuccess(T t);
    void onFailure(T t) throws Exception;
}

